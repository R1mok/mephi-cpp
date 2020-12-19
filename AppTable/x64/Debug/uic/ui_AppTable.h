/********************************************************************************
** Form generated from reading UI file 'AppTable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPTABLE_H
#define UI_APPTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppTableClass
{
public:
    QWidget *centralWidget;
    QPushButton *add;
    QPushButton *sale;
    QPushButton *show;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AppTableClass)
    {
        if (AppTableClass->objectName().isEmpty())
            AppTableClass->setObjectName(QString::fromUtf8("AppTableClass"));
        AppTableClass->resize(515, 405);
        centralWidget = new QWidget(AppTableClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        add = new QPushButton(centralWidget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(70, 40, 93, 28));
        sale = new QPushButton(centralWidget);
        sale->setObjectName(QString::fromUtf8("sale"));
        sale->setGeometry(QRect(200, 40, 93, 28));
        show = new QPushButton(centralWidget);
        show->setObjectName(QString::fromUtf8("show"));
        show->setGeometry(QRect(330, 40, 93, 28));
        AppTableClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AppTableClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 515, 26));
        AppTableClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AppTableClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AppTableClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AppTableClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AppTableClass->setStatusBar(statusBar);

        retranslateUi(AppTableClass);

        QMetaObject::connectSlotsByName(AppTableClass);
    } // setupUi

    void retranslateUi(QMainWindow *AppTableClass)
    {
        AppTableClass->setWindowTitle(QCoreApplication::translate("AppTableClass", "AppTable", nullptr));
        add->setText(QCoreApplication::translate("AppTableClass", "add", nullptr));
        sale->setText(QCoreApplication::translate("AppTableClass", "sale", nullptr));
        show->setText(QCoreApplication::translate("AppTableClass", "show", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppTableClass: public Ui_AppTableClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPTABLE_H
