#ifndef CHTWINDOW_H
#define CHTWINDOW_H
#include "string"
#include <QDialog>
#include "QTcpSocket"
#include "QHostAddress"
#include "QtNetwork"
#include "globalvar.h"
#include "QCloseEvent"
#include "vector"
#include "rdtrevwindow.h"
#include "udpfilerdtp.h"
using namespace std;
namespace Ui {
	class chtwindow;
}

class chtwindow : public QDialog
{
	Q_OBJECT

public:
	bool state;
	QHostAddress *serverIP;
	explicit chtwindow(QWidget *parent = 0);
	explicit chtwindow(QWidget *parent = 0, string ip_addr = "", string port = "", string username = "",bool state=0);
	~chtwindow();
	string id_addr;
	string port;
	QTcpSocket* chattcpsocket;
	string username;
	public slots:
	void pushButton_clicked();
	void slotConnected();
	void slotDisconnected();
	void dataReceived();
	void disconnect();
	void ChtwindowToHost(string);
	private slots:
	void on_lineEdit_editingFinished();
	void on_lineEdit_returnPressed();
private:
	void closeEvent(QCloseEvent *event);
	Ui::chtwindow *ui;
};

#endif // CHTWINDOW_H
