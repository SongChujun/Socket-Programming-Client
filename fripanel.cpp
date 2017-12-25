#include "fripanel.h"
#include "ui_fripanel.h"
#include "string"
#include "globalvar.h"
#include "chtwindow.h"
fripanel::fripanel(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::fripanel)
{
	ui->setupUi(this);
	server = new Server(this, 8011);
	connect(server, SIGNAL(updateServer(QString, int)), this, SLOT(updateServer(QString, int)));
	for (auto iter = friendmessage.begin(); iter != friendmessage.end(); iter++)
	{
		if ((*iter).second.empty())
		{
			ui->listWidget_2->addItem(QString::fromStdString((*iter).first));
		}
		else
		{
			ui->listWidget->addItem(QString::fromStdString((*iter).first));
		}
	}
}

fripanel::~fripanel()
{
	delete ui;
}

void fripanel::on_listWidget_itemActivated(QListWidgetItem *item)
{
	string username = (item->text()).toStdString();
	string ip_addr = friendmessage[username][0];
	string port = friendmessage[username][1];
	chtwindow* Chtwindow = new chtwindow(this, ip_addr, port, username, 1);
	Chtwindow->show();
}

void fripanel::on_listWidget_2_itemActivated(QListWidgetItem *item)
{
	string username = (item->text()).toStdString();
	string ip_addr = "";
	string port = "";
	chtwindow* Chtwindow = new chtwindow(this, ip_addr, port, username, 0);
	connect(this, SIGNAL(ChtwindowToHost(string)), Chtwindow, SLOT(ChtwindowToHost(string)));
	Chtwindow->show();
}
void fripanel::UpdateFripanel(QString msg)
{
	string stlmsg = msg.toStdString();
	vector<string> store;
	string tmp;
	string username;
	string ip_addr;
	string strport;
	int cnt = 0;
	size_t i = 0;
	for (i = 2; i<stlmsg.size(); i++)
	{
		while ((stlmsg[i] == ' ') && (stlmsg[i + 1] == ' '))
		{
			i++;
		}
		if (stlmsg[i] == ' ')
		{
			cnt++;
			if (cnt == 1)
			{
				username = tmp;
				tmp.clear();
			}
			else if (cnt == 2)
			{
				ip_addr = tmp;
				tmp.clear();
			}
			else if (cnt == 3)
			{
				strport = tmp.substr(0, 4);
				tmp.clear();
				store.push_back(ip_addr);
				store.push_back(strport);
				friendmessage[username] = store;
				store.clear();
				ui->listWidget->addItem(QString::fromStdString(username));
				QList<QListWidgetItem*> deleteditems = ui->listWidget_2->findItems(QString::fromStdString(username), Qt::MatchExactly);
				if (deleteditems.size() > 0)
				{
					ui->listWidget->removeItemWidget(deleteditems[0]);
					delete deleteditems[0];
				}
				break;
			}
		}
		else
		{
			tmp.push_back(stlmsg[i]);
		}
	}
	emit ChtwindowToHost(username);
}
void fripanel::closeEvent(QCloseEvent *event)
{

	emit CloseWindow();
	this->close();
}
void fripanel::ClientLogout(QString msg)
{
	string stdmsg = msg.toStdString();
	string username = "";
	for (size_t i = 2; i < stdmsg.size(); i++)
	{
		if (stdmsg[i] == ' ')
			break;
		username.push_back(stdmsg[i]);
	}
	friendmessage[username].clear();
	QList<QListWidgetItem*> deleteditems = ui->listWidget->findItems(QString::fromStdString(username), Qt::MatchExactly);
	if (deleteditems.size() > 0)
	{
		ui->listWidget->removeItemWidget(deleteditems[0]);
		delete deleteditems[0];
	}
	ui->listWidget_2->addItem(QString::fromStdString(username));
}