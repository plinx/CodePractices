#ifndef QTHELLO_H
#define QTHELLO_H

#include <QtWidgets/QMainWindow>
#include "ui_qthello.h"

class QtHello : public QMainWindow
{
	Q_OBJECT

public:
	QtHello(QWidget *parent = 0);
	~QtHello();

private:
	Ui::QtHelloClass ui;
};

#endif // QTHELLO_H
