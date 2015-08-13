/********************************************************************************
** Form generated from reading UI file 'qttable.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTABLE_H
#define UI_QTTABLE_H

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

class Ui_QtTableClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtTableClass)
    {
        if (QtTableClass->objectName().isEmpty())
            QtTableClass->setObjectName(QStringLiteral("QtTableClass"));
        QtTableClass->resize(600, 400);
        menuBar = new QMenuBar(QtTableClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtTableClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtTableClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtTableClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtTableClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtTableClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtTableClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtTableClass->setStatusBar(statusBar);

        retranslateUi(QtTableClass);

        QMetaObject::connectSlotsByName(QtTableClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtTableClass)
    {
        QtTableClass->setWindowTitle(QApplication::translate("QtTableClass", "QtTable", 0));
    } // retranslateUi

};

namespace Ui {
    class QtTableClass: public Ui_QtTableClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTABLE_H
