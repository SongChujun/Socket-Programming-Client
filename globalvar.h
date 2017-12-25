#ifndef GLOBALVAR_H
#define GLOBALVAR_H
#include "map"
#include  "QTcpSocket"
#include "string.h"
#include "QMessageBox"
#include "QListWidget"
#include "chtwindow.h"
#include "QFile"
#include "QUdpSocket"
#include "qmessagebox.h"
#include "rdtrevwindow.h"
#include "udpfilerdtp.h"
#include "vector"
#include <qhostaddress.h>
#include <qabstractsocket.h>
using namespace std;
extern map<string, vector<string>> friendmessage;
//extern map<string,chtwindow*> UserToChtwindow;
extern QString name;
int StrToInt(string& pc);
int BitsToInt(string& pc);
void StrToPc(char* result, string& s);
#endif // GLOBALVAR_H
