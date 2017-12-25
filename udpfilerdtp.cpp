#include "udpfilerdtp.h"
#include "ui_udpfilerdtp.h"
int flag = 0;
#define packet_size_N 500
UdpFileRDTP::UdpFileRDTP(QWidget *parent, QString filename) :
	QDialog(parent),
	ui(new Ui::UdpFileRDTP)
{
	test = new QByteArray(packet_size_N, '0');
	ui->setupUi(this);
	udpSocket = new QUdpSocket(this);
	connect(udpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
	WindowSizeN = 5;
	NumberSpace = 20;
	file = new QFile(filename);
	file->open(QIODevice::ReadOnly);
	in = new QDataStream(file);
	buf = new char[1500];
	port = 5555;
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
	serverIP = new QHostAddress();
	QString address = QNetworkInterface::allAddresses().first().toString();
	if (!(serverIP->setAddress(address)))
	{
		QMessageBox::information(this, tr("getaddress error"), tr("server ip address error!"));
	}
	bool res = udpSocket->bind(QHostAddress::Any, 5556);
	/*if (!res)
	{
	QMessageBox::information(this, tr("bind error"), tr("server ip address error!"));
	}*/
}

UdpFileRDTP::~UdpFileRDTP()
{
	delete ui;
}
void UdpFileRDTP::dataReceived()
{
	int flag = 0;
	string msg;
	QString Qmsg;
	while (udpSocket->hasPendingDatagrams())
	{
		if (flag == 1)
			return;
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		udpSocket->readDatagram(datagram.data(), datagram.size());
		Qmsg = datagram.data();
		string tmp = Qmsg.toStdString();
		if (tmp == "OK")
		{
			flag = 1;
			QMessageBox::information(this, tr("Congrats"), tr("Mission Complete!"));
		}
		int ACKNUM = (tmp[0] - '0') * 10 + (tmp[1] - '0');
		int i = 0;
		int length;
		if ((ACKNUM >send_base)||(ACKNUM+NumberSpace-send_base<=WindowSizeN))
		{
			if (ACKNUM > send_base)
			{
				length = ACKNUM - send_base;
			}
			else
			{
				length = ACKNUM + NumberSpace - send_base;
			}
			send_base = ACKNUM;
			for (i = 0; i < length; i++)
			{
				if (i == 0)
				{
					timer->start(100);
				}
				char bl = nextseqnum % 10 + '0';
				char bh = nextseqnum / 10 + '0';
				nextseqnum = (nextseqnum + 1) % NumberSpace;
				int res = in->readRawData(test->data(), packet_size_N);
				if (res == -1)
				{
					QMessageBox::information(this, tr("ReadRawData error"), tr("server ip address error!"));
				}
				if (res < packet_size_N)
				{
					test->resize(res);
				}
				QByteArray datagram = *test;
				datagram.push_front(bl);
				datagram.push_front(bh);
				window.erase(window.begin());
				window.push_back(*test);
				udpSocket->writeDatagram(datagram, *serverIP, port);
			}
		}
		else 
		{
			int beginnum = send_base;
			int length = (window.size() < WindowSizeN) ? window.size() : WindowSizeN;
			for (i = 0; i < length; i++)
			{
				if (i == 0)
				{
					timer->start(100);
				}
				char b1 = beginnum % 10 + '0';
				char b2 = beginnum / 10 + '0';
				beginnum = (beginnum + 1) % NumberSpace;
				QByteArray datagram = window[i];
				datagram.push_front(b1);
				datagram.push_front(b2);
				udpSocket->writeDatagram(datagram, *serverIP, port);
			}
		}
	}

}
void UdpFileRDTP::RdtSendFile()
{
	if (flag == 1)
		return;
	flag = 1;
	send_base = 0;
	nextseqnum = WindowSizeN;
	QString qmsg;
	string tmp;
	for (int i = 0; i<WindowSizeN; i++)
	{
		int res = in->readRawData(test->data(), packet_size_N);
		if (res == -1)
		{
			QMessageBox::information(this, tr("Read Error"), tr("server ip address error!"));
		}
		if (res<packet_size_N)
		{
			break;
		}
		/*tmp = (test->toStdString());
		if (window.size() > WindowSizeN)
			break;*/
		window.push_back(*test);
	}
	for (int i = 0; i<window.size(); i++)
	{
		QByteArray tmp = window[i];
		char bh = i / 10 + '0';
		char bl = i % 10 + '0';
		tmp.push_front(bl);
		tmp.push_front(bh);
		udpSocket->writeDatagram(tmp, *serverIP, port);
	}
}
void UdpFileRDTP::timeout()
{
	int beginnum = send_base;
	int length = (window.size() < WindowSizeN) ? window.size() : WindowSizeN;
	for (int i = 0; i < length; i++)
	{
		if (i == 0)
		{
			timer->start(100);
		}
		char b1 = beginnum % 10 + '0';
		char b2 = beginnum / 10 + '0';
		beginnum = (beginnum + 1) % NumberSpace;
		QByteArray datagram = window[i];
		datagram.push_front(b1);
		datagram.push_front(b2);
		udpSocket->writeDatagram(datagram, *serverIP, port);
	}
}

