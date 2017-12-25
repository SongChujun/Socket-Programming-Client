/********************************************************************************
** Form generated from reading UI file 'udpfilerdtp.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPFILERDTP_H
#define UI_UDPFILERDTP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_UdpFileRDTP
{
public:
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *UdpFileRDTP)
    {
        if (UdpFileRDTP->objectName().isEmpty())
            UdpFileRDTP->setObjectName(QStringLiteral("UdpFileRDTP"));
        UdpFileRDTP->resize(312, 170);
        progressBar = new QProgressBar(UdpFileRDTP);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(80, 90, 181, 23));
        progressBar->setValue(24);
        label = new QLabel(UdpFileRDTP);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 30, 54, 12));
        label_2 = new QLabel(UdpFileRDTP);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 70, 54, 12));

        retranslateUi(UdpFileRDTP);

        QMetaObject::connectSlotsByName(UdpFileRDTP);
    } // setupUi

    void retranslateUi(QDialog *UdpFileRDTP)
    {
        UdpFileRDTP->setWindowTitle(QApplication::translate("UdpFileRDTP", "Dialog", nullptr));
        label->setText(QApplication::translate("UdpFileRDTP", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("UdpFileRDTP", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UdpFileRDTP: public Ui_UdpFileRDTP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPFILERDTP_H
