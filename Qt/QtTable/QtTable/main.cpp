//#include "qttable.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QTableView>
#include "mymodel.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyModel mymodel;
	QTableView table;
	table.setModel(&mymodel);
	table.show();

	//QtTable w;
	//w.show();
	return a.exec();
}
