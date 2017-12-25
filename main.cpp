#include "mainwindow.h"
#include <QApplication>
#include <friendwindow.h>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QTextCodec::setCodecForTr(codecForLocale());
//    MainWindow w;
//    w.show();
    MainWindow w;
    w.show();
    return a.exec();
}
