#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>
#include <QTcpSocket>
#include "friendwindow.h"
#include "map"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT
public:
    Chatwindow* chatwindow;
private:
    int port;
    QHostAddress *serverIP;
    QString userNmae;
    QString password;
    QTcpSocket *tcpSocket;
signals:
	void UpdateFripanel(QString);
	void ClientLogout(QString);
public slots:
	void pushButton_3_clicked();
	void CloseWindow();
    void slotConnected();
    void slotDisconnected();
    void dataReceived();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

//    void on_lineEdit_editingFinished();

//    void on_lineEdit_2_editingFinished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
