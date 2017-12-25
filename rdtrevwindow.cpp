#include "rdtrevwindow.h"
#include "ui_rdtrevwindow.h"
#define Packet_Size_N 500
#define windowsize 10
#define numberspace 20
long int cnt;
RdtRevWindow::RdtRevWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::RdtRevWindow)
{
	file = new QFile("C:/Users/92550/Desktop/file");
	if (!file->open(QIODevice::WriteOnly))
	{
		QMessageBox::information(this, tr("openfileerroe!"), tr("server ip address error!"));
	}
	out = new QDataStream(file);
	buf = new char[1500];
	ui->setupUi(this);
	SeverSocket = new QUdpSocket(this);
	serverIP = new QHostAddress();
	test = new QByteArray(1402, '0');
	QString address = QNetworkInterface::allAddresses().first().toString();
	serverIP->setAddress(address);
	/*if (!(serverIP->setAddress(QHostAddress::Any)))
	{
	QMessageBox::information(this, tr("getaddress error"), tr("server ip address error!"));
	}*/
	int port = 5555;
	bool res = SeverSocket->bind(QHostAddress::Any, 5555);
	if (!res)
	{
		QMessageBox::information(this, tr("bind error"), tr("server ip address error!"));
		qDebug() << SeverSocket->error() << SeverSocket->errorString();
	}
	connect(SeverSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
	expect_num = 0;
}

RdtRevWindow::~RdtRevWindow()
{
	delete ui;
}
void RdtRevWindow::dataReceived()
{
	int res = 0;
	if (this->isVisible() == false)
	{
		this->show();
	}
	int flag = 0;
	QString qmsg;
	string stdmsg;
	while (SeverSocket->hasPendingDatagrams())
	{
		if (flag == 1)
			return;
		QByteArray datagram;
		datagram.resize(SeverSocket->pendingDatagramSize());
		SeverSocket->readDatagram(datagram.data(), datagram.size());
		stdmsg.clear();
		for (int j = 0; j < datagram.size(); j++)
		{
			stdmsg.push_back(datagram[j]);
		}
		if (stdmsg.size() < 2)
		{
			file->close();
		}
		int revnum = (stdmsg[0] - '0') * 10 + (stdmsg[1] - '0');
		datagram.remove(0, 2);
		stdmsg.erase(0, 2);
		if (revnum == expect_num)
		{
			cnt++;
			expect_num = (expect_num + 1) % numberspace;
			if (stdmsg.size()<Packet_Size_N)
			{
				flag = 1;
				stdmsg = qmsg.toStdString();
				out->writeRawData(datagram.data(), datagram.size());
				file->close();
				qmsg = "OK";
				SeverSocket->writeDatagram(qmsg.toLatin1(), *serverIP, 5556);
			}
			else
			{
				out->writeRawData(datagram.data(), Packet_Size_N);
				char b1 = expect_num % 10 + '0';
				char b2 = expect_num / 10 + '0';
				qmsg.clear();
				qmsg.push_back(b2);
				qmsg.push_back(b1);
				SeverSocket->writeDatagram(qmsg.toLatin1(), qmsg.length(), *serverIP, 5556);
			}
		}
		else
		{
			char b1 = expect_num % 10 + '0';
			char b2 = expect_num / 10 + '0';
			qmsg.clear();
			qmsg.push_back(b2);
			qmsg.push_back(b1);
			SeverSocket->writeDatagram(qmsg.toLatin1(), qmsg.length(), *serverIP, 5556);
		}

	}
}
