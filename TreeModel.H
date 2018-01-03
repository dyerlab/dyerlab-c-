#ifndef TREEMODEL_H
#define TREEMODEL_H

#include "TreeItem.H"

#include <QObject>
#include <QAbstractItemModel>

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    TreeModel(QList<QVariant> data, QObject *parent = 0 );
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    inline TreeItem* getRoot()          { return m_rootItem; }

private:
    TreeItem *m_rootItem;
    QStringList m_headers;

    TreeItem* getItem( const QModelIndex &index ) const;
};

#endif // TREEMODEL_H
