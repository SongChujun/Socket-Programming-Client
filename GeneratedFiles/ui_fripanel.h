/********************************************************************************
** Form generated from reading UI file 'fripanel.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIPANEL_H
#define UI_FRIPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_fripanel
{
public:
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QLabel *label;

    void setupUi(QDialog *fripanel)
    {
        if (fripanel->objectName().isEmpty())
            fripanel->setObjectName(QStringLiteral("fripanel"));
        fripanel->resize(216, 424);
        listWidget = new QListWidget(fripanel);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 40, 171, 171));
        listWidget_2 = new QListWidget(fripanel);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(20, 230, 171, 161));
        label = new QLabel(fripanel);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 10, 54, 12));

        retranslateUi(fripanel);

        QMetaObject::connectSlotsByName(fripanel);
    } // setupUi

    void retranslateUi(QDialog *fripanel)
    {
        fripanel->setWindowTitle(QApplication::translate("fripanel", "Dialog", nullptr));
        label->setText(QApplication::translate("fripanel", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fripanel: public Ui_fripanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIPANEL_H
