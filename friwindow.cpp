#include "friwindow.h"
#include "string"
#include "globalvar.h"
#include "chtwindow.h"
int port=8011;
//using namespace std;
FriWindow::FriWindow(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::FriWindow)
{
    ui->setupUi(this);
    server = new Server(this,port);
    connect(server,SIGNAL(updateServer(QString,int)),this,SLOT(updateServer(QString,int)));
    for(auto iter=friendmessage.begin();iter!=friendmessage.end();iter++)
    {
        if((*iter).second.empty())
        {
            ui->listWidget_2->addItem((*iter).first);
        }
        else
        {
            ui->listWidget->addItem((*iter).first);
        }
    }
}

FriWindow::~FriWindow()
{
    delete ui;
}

void FriWindow::on_listWidget_itemActivated(QListWidgetItem *item)
{
    string username=(item->text()).toStdString();
    string ip_addr=friendmessage[username][0];
    string port=friendmessage[username][1];
    chtwindow* Chtwindow=new chtwindow(this,username,ip_addr,port);
    Chtwindow->show();
}

void FriWindow::on_listWidget_2_itemActivated(QListWidgetItem *item)
{
    /*wait to be written*/
}
void FriWindow::updateServer(QString,int)
{
    /*wait to be written*/
}
