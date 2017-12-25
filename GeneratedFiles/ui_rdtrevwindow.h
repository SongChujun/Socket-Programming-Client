/********************************************************************************
** Form generated from reading UI file 'rdtrevwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RDTREVWINDOW_H
#define UI_RDTREVWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_RdtRevWindow
{
public:
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *RdtRevWindow)
    {
        if (RdtRevWindow->objectName().isEmpty())
            RdtRevWindow->setObjectName(QStringLiteral("RdtRevWindow"));
        RdtRevWindow->resize(400, 150);
        progressBar = new QProgressBar(RdtRevWindow);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(130, 100, 118, 23));
        progressBar->setValue(24);
        label = new QLabel(RdtRevWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 60, 54, 12));
        label_2 = new QLabel(RdtRevWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 30, 54, 12));

        retranslateUi(RdtRevWindow);

        QMetaObject::connectSlotsByName(RdtRevWindow);
    } // setupUi

    void retranslateUi(QDialog *RdtRevWindow)
    {
        RdtRevWindow->setWindowTitle(QApplication::translate("RdtRevWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("RdtRevWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("RdtRevWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RdtRevWindow: public Ui_RdtRevWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RDTREVWINDOW_H
