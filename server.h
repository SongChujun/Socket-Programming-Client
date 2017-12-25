#ifndef SERVER_H
#define SERVER_H
#include <QObject>
#include <QTcpServer>
#include <revwindow.h>
#include "map"
class Server:public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent=0,int port=0);
public slots:
    void execute();
    void slotDisconnected(int);
    void readMessage();
protected:
    void incommingConnection(int socketDescriptor);
};

#endif // SERVER_H
