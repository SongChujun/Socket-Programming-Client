#include "server.h"
#include "QMessageBox"
#include "QTcpSocket"
#include "QIODevice"
#include "QObject"
#include "globalvar.h"
#include "revwindow.h"
using namespace std;
QString ACK;
int port=8010;
Server::Server(QObject *parent,int port)
    :QTcpServer(parent)
{
    listen(QHostAddress::Any,8011);
    connect(this,SIGNAL(newConnection()),this,SLOT(execute()));
}
void Server::incommingConnection(int socketDescriptor)
{
}
void Server::slotDisconnected(int Descriptor)
{
}
void Server::execute()
{
	//QMessageBox::warning(NULL, "warning", "incomming connection!", QMessageBox::Yes, QMessageBox::Yes);
	revwindow* REVWINDOW = new revwindow;
	REVWINDOW->m_tcpSocket = this->nextPendingConnection();
	connect(REVWINDOW->m_tcpSocket, SIGNAL(readyRead()), REVWINDOW, SLOT(readMessage()));
	connect(REVWINDOW->m_tcpSocket, SIGNAL(disconnected()), REVWINDOW, SLOT(disconnect()));
	REVWINDOW->show();
}
void Server::readMessage()
{
}

