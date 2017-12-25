/********************************************************************************
** Form generated from reading UI file 'chtwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHTWINDOW_H
#define UI_CHTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_chtwindow
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *chtwindow)
    {
        if (chtwindow->objectName().isEmpty())
            chtwindow->setObjectName(QStringLiteral("chtwindow"));
        chtwindow->resize(242, 331);
        label = new QLabel(chtwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 20, 81, 16));
        lineEdit = new QLineEdit(chtwindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(32, 250, 191, 20));
        listWidget = new QListWidget(chtwindow);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 50, 191, 192));
        pushButton = new QPushButton(chtwindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(54, 280, 111, 23));

        retranslateUi(chtwindow);

        QMetaObject::connectSlotsByName(chtwindow);
    } // setupUi

    void retranslateUi(QDialog *chtwindow)
    {
        chtwindow->setWindowTitle(QApplication::translate("chtwindow", "Dialog", nullptr));
        label->setText(QApplication::translate("chtwindow", "TextLabel", nullptr));
        pushButton->setText(QApplication::translate("chtwindow", "FileTransmission", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chtwindow: public Ui_chtwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHTWINDOW_H
