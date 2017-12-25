#include "friendwindow.h"
#include "ui_chatwindow.h"
#include "qfiledialog.h"
#include "globalvar.h"
using namespace std;
Chatwindow::Chatwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chatwindow)
{
    ui->setupUi(this);
    for(auto iter=friendmessage.begin();iter！=friendmessage.end();iter++)
    {
        if(((*iter).second())[0]=="                  ";
        {
            ui->listWidget_3->addItem((*iter)->first());
        }
        else
        {
            ui->listWidget_2->addItem((*iter)->first());
        }
    }
}

Chatwindow::~Chatwindow()
{
    delete ui;
}

void Chatwindow::on_pushButton_clicked()
{
    QString file_full, file_name, file_path;
    QFileInfo fi;

    file_full = QFileDialog::getOpenFileName(this);

    fi = QFileInfo(file_full);
    file_name = fi.fileName();
    file_path = fi.absolutePath();
    /*UDP reliable file transmission protocol;*/
}

void Chatwindow::on_listWidget_2_itemActivated(QListWidgetItem *item)
{
    string username=item->text();
    string ip_addr=friendmessage[username][0];
    string strport=friendmessage[username][1];
}
void Chatwindow::on_listWidget_3_itemActivated(QListWidgetItem *item)
{
    /*wait to be written*/
}
