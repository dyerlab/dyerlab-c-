#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include "Population.H"

#include <QObject>
#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableModel(Population *population);

    // overrides
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

private:
    Population *m_population;
    QStringList m_headers;



};

#endif // TABLEMODEL_H
