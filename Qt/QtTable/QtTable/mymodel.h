#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>

class MyModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	MyModel(QObject *parent = 0);
	int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
	int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
};

#endif // MYMODEL_H
