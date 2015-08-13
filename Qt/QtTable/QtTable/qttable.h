#ifndef QTTABLE_H
#define QTTABLE_H

#include <QtWidgets/QMainWindow>
#include "ui_qttable.h"

class QtTable : public QMainWindow
{
	Q_OBJECT

public:
	QtTable(QWidget *parent = 0);
	~QtTable();

private:
	Ui::QtTableClass ui;
};

#endif // QTTABLE_H
