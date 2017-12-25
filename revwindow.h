#ifndef REVWINDOW_H
#define REVWINDOW_H
#include "QTcpSocket"
#include <QDialog>
#include "globalvar.h"
#include "QCloseEvent"
#include "rdtrevwindow.h"
namespace Ui {
	class revwindow;
}

class revwindow : public QDialog
{
	Q_OBJECT
		signals :
	void newmsg(QString);
public:
	QTcpSocket* m_tcpSocket;
	RdtRevWindow* RDTREVWINDOW;
	explicit revwindow(QWidget *parent = 0);
	~revwindow();
	public slots:
	//    void slotConnected();
	//    void slotDisconnected();
	void readMessage();
	void updateRevwindow(QString, int);
	void disconnect();
	private slots:
	void on_lineEdit_editingFinished();
private:
	Ui::revwindow *ui;
	void closeEvent(QCloseEvent *event);
};

#endif // REVWINDOW_H
