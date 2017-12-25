#ifndef RDTREVWINDOW_H
#define RDTREVWINDOW_H
#include <QDialog>
#include "globalvar.h"
#include <QHostAddress>
namespace Ui {
	class RdtRevWindow;
}

class RdtRevWindow : public QDialog
{
	Q_OBJECT

public:
	QHostAddress *serverIP;
	QUdpSocket* SeverSocket;
	explicit RdtRevWindow(QWidget *parent = 0);
	~RdtRevWindow();
	QFile *file;
	QDataStream *out;
	char* buf;
	QByteArray *test;
	int expect_num;
	public slots:
	void dataReceived();
private:
	Ui::RdtRevWindow *ui;
};

#endif // RDTREVWINDOW_H
