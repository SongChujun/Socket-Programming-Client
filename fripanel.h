#ifndef FRIPANEL_H
#define FRIPANEL_H
#include "QListWidget"
#include <QDialog>
#include "server.h"
#include <QDialog>

namespace Ui {
class fripanel;
}

class fripanel : public QDialog
{
    Q_OBJECT
signals:
	void CloseWindow();
	void ChtwindowToHost(string);
public slots:
	void UpdateFripanel(QString);
	void ClientLogout(QString);
public:
    explicit fripanel(QWidget *parent = 0);
    ~fripanel();
    Server* server;
private slots:
    void on_listWidget_itemActivated(QListWidgetItem *item);

    void on_listWidget_2_itemActivated(QListWidgetItem *item);

private:
    Ui::fripanel *ui;
	void closeEvent(QCloseEvent *event);
};

#endif // FRIPANEL_H
