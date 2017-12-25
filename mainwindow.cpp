#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QHostInfo>
#include <QtNetwork>
#include <server.h>
#include "string.h"
#include "globalvar.h"
#include "fripanel.h"
#include "map"
using namespace  std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_1->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->label_1->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->setText(tr("Username"));
    ui->label_5->setText(tr("Password"));
    ui->label_4->show();
    ui->label_5->show();
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
	connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(pushButton_3_clicked()));
    serverIP=new QHostAddress();
    QString address = QNetworkInterface::allAddresses().first().toString();
    if(!(serverIP->setAddress(address)))
    {
        QMessageBox::information(this,tr("error"),tr("server ip address error!"));
        return;
    }
    tcpSocket->connectToHost(*serverIP,8010);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//zhuce sign up
{
    if(ui->label_3->text()!=tr("Confirm Password")||(ui->label_3->isVisible()==false))
    {
        ui->lineEdit_1->show();
        ui->lineEdit_1->clear();
        ui->lineEdit_2->show();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->show();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->show();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->show();
        ui->lineEdit_5->clear();
        ui->label_1->show();
        ui->label_2->show();
        ui->label_3->show();
        (ui->label_1)->setText(tr("Username"));
        (ui->label_2)->setText((tr("Password")));
        (ui->label_3)->setText((tr("Confirm Password")));
        (ui->label_4)->setText((tr("Protection Question")));
        (ui->label_5)->setText((tr("Protection Answer")));

    }
    else
    {
        if((ui->label_1)->text()=="")
        {
            QMessageBox::warning(NULL, "warning", "No username!", QMessageBox::Yes, QMessageBox::Yes);
        }
        else if(ui->lineEdit_2->text()=="")
        {
            QMessageBox::warning(NULL, "warning", "No password!", QMessageBox::Yes, QMessageBox::Yes);
        }
        else if(ui->lineEdit_3->text()=="")
        {
            QMessageBox::warning(NULL, "warning", "Please confirm your password!", QMessageBox::Yes, QMessageBox::Yes);
        }
        else if((ui->lineEdit_2->text())!=(ui->lineEdit_3->text()))
        {
            QMessageBox::warning(NULL, "warning", "Two Passwords don't match!", QMessageBox::Yes, QMessageBox::Yes);
        }
        else if(ui->lineEdit_4->text()=="")
        {
            QMessageBox::warning(NULL, "warning", "Please enter protection question!", QMessageBox::Yes, QMessageBox::Yes);
        }
        else if(ui->lineEdit_5->text()=="")
        {
            QMessageBox::warning(NULL, "warning", "Please enter protection answer!", QMessageBox::Yes, QMessageBox::Yes);
        }
        else
        {
            QString SignupMessage;
            SignupMessage.append("UP");
            SignupMessage.append(" ");
            SignupMessage.append((ui->lineEdit_1)->text());
            name=ui->lineEdit_1->text();
            SignupMessage.append(" ");
            SignupMessage.append((ui->lineEdit_2)->text());
            SignupMessage.append(" ");
            SignupMessage.append((ui->lineEdit_4)->text());
            SignupMessage.append(" ");
            SignupMessage.append((ui->lineEdit_5)->text());
            QString ip_addr = QNetworkInterface::allAddresses().first().toString();
            SignupMessage.append(" ");
            SignupMessage.append(ip_addr);
            QString strport="8011";
            SignupMessage.append(" ");
            SignupMessage.append(strport);  
			SignupMessage.append(" ");
            tcpSocket->write(SignupMessage.toLatin1(),SignupMessage.length());
        }
    }
}

void MainWindow::on_pushButton_2_clicked()//denglu Sign in
{
    if(((ui->label_3)->isVisible())==true)
    {
        ui->label_1->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->lineEdit_1->hide();
        ui->lineEdit_2->hide();
        ui->lineEdit_3->hide();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->label_4->setText(tr("Username"));
        ui->label_5->setText(tr("Password"));
    }
    else
    {
        if(((ui->lineEdit_4)->text())=="")
        {
            QMessageBox::information(NULL, "information", "empty username!", QMessageBox::Yes, QMessageBox::Yes);
        }
        else if(((ui->lineEdit_5)->text())=="")
        {
            QMessageBox::information(NULL, "information", "empty password!", QMessageBox::Yes, QMessageBox::Yes);
        }
        else
        {
            QString SignipMessage;
            SignipMessage.append("IN");
            SignipMessage.append(" ");
            SignipMessage.append((ui->lineEdit_4)->text());
            name=ui->lineEdit_4->text();
            SignipMessage.append(" ");
            SignipMessage.append((ui->lineEdit_5)->text());
            QString ip_addr = QNetworkInterface::allAddresses().first().toString();
            SignipMessage.append(" ");
            SignipMessage.append(ip_addr);
            QString strport="8011";
            SignipMessage.append(" ");
            SignipMessage.append(strport);  
            tcpSocket->write(SignipMessage.toLatin1(),SignipMessage.length());
        }
    }
}
void MainWindow::pushButton_3_clicked()
{
	if (((ui->label_2)->text() != tr("Protque"))&&(((ui->label_3)->text() != tr("Protans"))))
	{
		ui->label_1->show();
		ui->label_2->show();
		ui->label_3->show();
		ui->label_4->show();
		ui->label_5->show();
		ui->lineEdit_1->show();
		ui->lineEdit_2->show();
		ui->lineEdit_3->show();
		ui->lineEdit_4->show();
		ui->lineEdit_5->show();
		ui->lineEdit_1->clear();
		ui->lineEdit_2->clear();
		ui->lineEdit_3->clear();
		ui->lineEdit_4->clear();
		ui->lineEdit_5->clear();
		ui->label_1->setText(tr("Username"));
		ui->label_2->setText(tr("Protque"));
		ui->label_3->setText(tr("Protans"));
		ui->label_4->setText(tr("Password"));
		ui->label_5->setText(tr("Confirm Password"));
	}
	else
	{
		if (((ui->lineEdit_1)->text()) == "")
		{
			QMessageBox::information(NULL, "information", "empty username!", QMessageBox::Yes, QMessageBox::Yes);
		}
		else if (((ui->lineEdit_2)->text()) == "")
		{
			QMessageBox::information(NULL, "information", "empty protque!", QMessageBox::Yes, QMessageBox::Yes);
		}
		else if (((ui->lineEdit_3)->text()) == "")
		{
			QMessageBox::information(NULL, "information", "empty protans!", QMessageBox::Yes, QMessageBox::Yes);
		}
		else if (((ui->lineEdit_4)->text()) == "")
		{
			QMessageBox::information(NULL, "information", "empty password!", QMessageBox::Yes, QMessageBox::Yes);
		}
		else if (((ui->lineEdit_5)->text()) == "")
		{
			QMessageBox::information(NULL, "information", "empty password!", QMessageBox::Yes, QMessageBox::Yes);
		}
		else if (ui->lineEdit_4->text()!=(ui->lineEdit_5->text()))
		{
			QMessageBox::information(NULL, "information", "passwords don't match!", QMessageBox::Yes, QMessageBox::Yes);
		}
		else
		{
			QString SignipMessage;
			SignipMessage.append("RE");
			SignipMessage.append(" ");
			SignipMessage.append((ui->lineEdit_1)->text());
			SignipMessage.append(" ");
			SignipMessage.append((ui->lineEdit_2)->text());
			SignipMessage.append(" ");
			SignipMessage.append((ui->lineEdit_3)->text());
			SignipMessage.append(" ");
			SignipMessage.append((ui->lineEdit_4)->text());
			SignipMessage.append(" ");
			tcpSocket->write(SignipMessage.toLatin1(), SignipMessage.length());
		}
	}
}
void MainWindow::slotConnected()
{
    QMessageBox::warning(NULL, "warning", "connected!", QMessageBox::Yes, QMessageBox::Yes);
}
void MainWindow::slotDisconnected()
{
    QString msg="exit";
    tcpSocket->write(msg.toLatin1(),msg.length());
}
void MainWindow::dataReceived()
{
    while ((tcpSocket->bytesAvailable())>0)
    {
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());
        tcpSocket->read(datagram.data(),datagram.size());
        QString msg=datagram.data();
        string stlmsg=msg.toStdString();
        if(msg[0]=='4'||msg[0]=='3')
        {
            int i=0;
            vector<string> store;
            string tmp;
            string username;
            string ip_addr;
            string strport;
            int cnt=0;
            for(i=2;i<stlmsg.size();i++)
            {
               
                while((stlmsg[i]==' ')&&(stlmsg[i+1]==' '))
                {
                    i++;
                }
                if(stlmsg[i]==' ')
                {
                    cnt++;
                    if(cnt==1)
                    {
                        username=tmp;
                        tmp.clear();
                    }
                    else if(cnt==2)
                    {
                        ip_addr=tmp;
                        tmp.clear();
                    }
                    else if(cnt==3)
                    {
                        strport=tmp.substr(0,4);
                        tmp.clear();
                        cnt=0;
                        store.push_back(ip_addr);
                        store.push_back(strport);
                        friendmessage[username]=store;
                        store.clear();
                    }
                    tmp.clear();
                }
                else
                {
                    tmp.push_back(stlmsg[i]);
                }
				if ((stlmsg[i] == ' ') && (stlmsg[i + 1] == '|') && (stlmsg[i + 2] == '|'))
					break;
            }
			tmp.clear();
            for(i=i+4;i<stlmsg.size();i++)
            {
                if(stlmsg[i]==' ')
                {
                    username=tmp;
                    tmp.clear();
                    friendmessage[username]={};
                }
                else
                {
                    tmp.push_back(stlmsg[i]);
                }
            }
            fripanel* FRIPANEL=new fripanel(this);
			connect(this, SIGNAL(UpdateFripanel(QString)), FRIPANEL, SLOT(UpdateFripanel(QString)));
			connect(FRIPANEL, SIGNAL(CloseWindow()), this, SLOT(CloseWindow()));
			connect(this, SIGNAL(ClientLogout(QString)), FRIPANEL, SLOT(ClientLogout(QString)));
            this->hide();
            FRIPANEL->show();
        }
		else if (msg[0] == '5')
		{
			emit UpdateFripanel(msg);
		}
		else if(msg[0]=='0')
        {
            QMessageBox::information(NULL, "information", "No User!", QMessageBox::Yes, QMessageBox::Yes);
        }
        else if(msg[0]=='1')
        {
            QMessageBox::information(NULL,"information","Incorrect Password",QMessageBox::Yes,QMessageBox::Yes);
        }
		else if (msg[0] == '6')
		{
			emit ClientLogout(msg);
		}
		else if (msg[0] == '7')
		{
			QMessageBox::information(NULL, "information", "User Already online!", QMessageBox::Yes, QMessageBox::Yes);
		}
    }
}

void MainWindow::CloseWindow()
{
	QString ACK = "";
	ACK.append("OT");
	ACK.append(" ");
	ACK.append(name);
	ACK.append(" ");
	tcpSocket->write(ACK.toLatin1(), ACK.size());
	tcpSocket->disconnectFromHost();
	this->close();
}

