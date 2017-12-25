/********************************************************************************
** Form generated from reading UI file 'revwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVWINDOW_H
#define UI_REVWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_revwindow
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *revwindow)
    {
        if (revwindow->objectName().isEmpty())
            revwindow->setObjectName(QStringLiteral("revwindow"));
        revwindow->resize(285, 338);
        listWidget = new QListWidget(revwindow);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 50, 256, 231));
        label = new QLabel(revwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 20, 54, 12));
        lineEdit = new QLineEdit(revwindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(22, 300, 251, 20));

        retranslateUi(revwindow);

        QMetaObject::connectSlotsByName(revwindow);
    } // setupUi

    void retranslateUi(QDialog *revwindow)
    {
        revwindow->setWindowTitle(QApplication::translate("revwindow", "Dialog", nullptr));
        label->setText(QApplication::translate("revwindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class revwindow: public Ui_revwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVWINDOW_H
