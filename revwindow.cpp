#include "revwindow.h"
#include "ui_revwindow.h"

revwindow::revwindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::revwindow)
{
	ui->setupUi(this);
	RDTREVWINDOW = new RdtRevWindow(this);
}

revwindow::~revwindow()
{
	delete ui;
}
void revwindow::on_lineEdit_editingFinished()
{
	if (ui->lineEdit->text() == "")
		return;
	else
	{
		m_tcpSocket->write(ui->lineEdit->text().toLatin1(), ui->lineEdit->text().size());
		ui->listWidget->addItem(ui->lineEdit->text());
		ui->lineEdit->clear();
	}
}
void revwindow::updateRevwindow(QString msg, int n)
{
	ui->listWidget->addItem(msg);
}
//void revwindow::slotDisconnected()
//{

//}
//void revwindow::slotConnected()
//{

//}
void revwindow::readMessage()
{
	while ((m_tcpSocket->bytesAvailable())>0)
	{
		int length = m_tcpSocket->bytesAvailable();
		char buf[1024];
		m_tcpSocket->read(buf, length);
		QString msg = buf;
		msg.resize(length);
		ui->listWidget->addItem(msg);
	}
}
void revwindow::disconnect()
{
	this->hide();
}
void revwindow::closeEvent(QCloseEvent *event)
{
	m_tcpSocket->disconnectFromHost();
	this->hide();
	event->ignore();
}
