/********************************************************************************
** Form generated from reading UI file 'qthello.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTHELLO_H
#define UI_QTHELLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtHelloClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtHelloClass)
    {
        if (QtHelloClass->objectName().isEmpty())
            QtHelloClass->setObjectName(QStringLiteral("QtHelloClass"));
        QtHelloClass->resize(600, 400);
        menuBar = new QMenuBar(QtHelloClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtHelloClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtHelloClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtHelloClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtHelloClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtHelloClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtHelloClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtHelloClass->setStatusBar(statusBar);

        retranslateUi(QtHelloClass);

        QMetaObject::connectSlotsByName(QtHelloClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtHelloClass)
    {
        QtHelloClass->setWindowTitle(QApplication::translate("QtHelloClass", "QtHello", 0));
    } // retranslateUi

};

namespace Ui {
    class QtHelloClass: public Ui_QtHelloClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTHELLO_H
