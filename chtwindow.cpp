#include "chtwindow.h"
#include "ui_chtwindow.h"
#include "string"
#include "qfiledialog.h"
#include "qfileinfo.h"
using namespace std;
QString offlinemsg;
chtwindow::chtwindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::chtwindow)
{
	ui->setupUi(this);
}
chtwindow::chtwindow(QWidget *parent, string ip_addr, string port, string username,bool statein) :
	QDialog(parent),
	ui(new Ui::chtwindow)
{
	ui->setupUi(this);
	ui->pushButton->setAutoDefault(false);
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButton_clicked()));
	ui->label->setText(QString::fromStdString(username));
	chattcpsocket = new QTcpSocket(this);
	connect(chattcpsocket, SIGNAL(disconnected()), this, SLOT(disconnect()));
	int intport = QString::fromStdString(port).toInt();
	state = statein;
	serverIP = new QHostAddress();
	QString address = QNetworkInterface::allAddresses().first().toString();
	if (!(serverIP->setAddress(address)))
	{
		QMessageBox::information(this, tr("error"), tr("server ip address error!"));
		return;
	}
	if (state)
	{
		chattcpsocket->connectToHost(*serverIP, intport);
		connect(chattcpsocket, SIGNAL(connected()), this, SLOT(slotConnected()));
		connect(chattcpsocket, SIGNAL(disconnected()), this, SLOT(disconnect()));
		connect(chattcpsocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
	}
	//RdtRevWindow *RDTREVWINDOW = new RdtRevWindow(this);
}

chtwindow::~chtwindow()
{
	delete ui;
}
void chtwindow::dataReceived()
{
	while ((chattcpsocket->bytesAvailable())>0)
	{
		QByteArray datagram;
		datagram.resize(chattcpsocket->bytesAvailable());
		chattcpsocket->read(datagram.data(), datagram.size());
		QString msg = datagram.data();
		ui->listWidget->addItem(msg);
	}
}
void chtwindow::on_lineEdit_editingFinished()
{
}
void chtwindow::slotDisconnected()
{

}
void chtwindow::slotConnected()
{

}

void chtwindow::on_lineEdit_returnPressed()
{
	if (state)
	{
		if (ui->lineEdit->text() == "")
			return;
		else
		{
			ui->listWidget->addItem(ui->lineEdit->text());
			chattcpsocket->write(ui->lineEdit->text().toLatin1(), ui->lineEdit->text().size());
			ui->lineEdit->clear();
		}
	}
	else
	{
		offlinemsg.append(ui->lineEdit->text());
		ui->listWidget->addItem(ui->lineEdit->text());
		ui->lineEdit->clear();
	}
}
void chtwindow::disconnect()
{
	this->close();
}
void chtwindow::closeEvent(QCloseEvent *event)
{
	chattcpsocket->disconnectFromHost();
	event->accept();
}
void chtwindow::ChtwindowToHost(string username)
{
	string ip_addr = friendmessage[username][0];
	string port = friendmessage[username][1];
	int intport = QString::fromStdString(port).toInt();
	serverIP = new QHostAddress();
	QString address = QNetworkInterface::allAddresses().first().toString();
	if (!(serverIP->setAddress(address)))
	{
		QMessageBox::information(this, tr("error"), tr("server ip address error!"));
		return;
	}
	chattcpsocket->connectToHost(*serverIP, intport);
	connect(chattcpsocket, SIGNAL(connected()), this, SLOT(slotConnected()));
	connect(chattcpsocket, SIGNAL(disconnected()), this, SLOT(disconnect()));
	connect(chattcpsocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
	chattcpsocket->write(offlinemsg.toLatin1(), offlinemsg.size());
	offlinemsg.clear();
	state = 1;
}
void chtwindow::pushButton_clicked()
{
	QString file_full, file_name, file_path;
	QFileInfo fi;
	file_full = QFileDialog::getOpenFileName(this);

	fi = QFileInfo(file_full);
	file_name = fi.fileName();
	file_path = fi.filePath();
	//QString file_path = "C:/Users/92550/Desktop/Test.part";
	UdpFileRDTP* UDPFILERDTP = new UdpFileRDTP(this, file_path);
	UDPFILERDTP->RdtSendFile();
}