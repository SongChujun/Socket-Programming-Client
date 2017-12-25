#ifndef UDPFILERDTP_H
#define UDPFILERDTP_H
#include <QDialog>
#include "globalvar.h"
#include "QTime"
using namespace std;
namespace Ui {
class UdpFileRDTP;
}

class UdpFileRDTP : public QDialog
{
    Q_OBJECT

public:
    int WindowSizeN;
    int NumberSpace;
    int send_base;
    int nextseqnum;
    int port;
    char* buf;
    QFile *file;
    QDataStream* in;
	QList<QByteArray> window;
	QByteArray *test;
	QHostAddress* serverIP;
    //explicit UdpFileRDTP(QWidget *parent = 0);
	explicit UdpFileRDTP(QWidget *parent = 0, QString filename = 0);
    QUdpSocket* udpSocket;
    void RdtSendFile();
    ~UdpFileRDTP();
    QTimer* timer;
public slots:
    void dataReceived();
    void timeout();
private:
    Ui::UdpFileRDTP *ui;
};

#endif // UDPFILERDTP_H
