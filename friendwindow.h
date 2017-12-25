#ifndef FRIENDWINDOW_H
#define FRIENDWINDOW_H
#include <QDialog>
#include "server.h"
#include "map"
#include "string"
#include "QListWidgetItem"
namespace Ui {
class Chatwindow;
}

class Chatwindow : public QDialog
{
    Q_OBJECT

public:
    Server *server;
    explicit Chatwindow(QWidget *parent = 0);
    ~Chatwindow();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_2_itemActivated(QListWidgetItem *item);

    void on_listWidget_3_activated(const QModelIndex &index);

    void on_listWidget_3_itemActivated(QListWidgetItem *item);

private:
    Ui::Chatwindow *ui;
};
//map<string,QTcpSocket*>;
#endif // CHATWINDOW_H
