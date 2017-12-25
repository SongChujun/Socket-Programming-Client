#ifndef FRIWINDOW_H
#define FRIWINDOW_H
#include "QListWidget"
#include <QDialog>
#include "server.h"
namespace Ui {
class FriWindow;
}

class FriWindow : public QDialog
{
    Q_OBJECT
public:
    Server* server;
    explicit FriWindow(QWidget *parent = 0);
    ~FriWindow();
private slots:
    void on_listWidget_itemActivated(QListWidgetItem *item);
    void updateServer(QString,int);
    void on_listWidget_2_itemActivated(QListWidgetItem *item);

private:
    Ui::FriWindow *ui;
};

#endif // FRIWINDOW_H
