#include "TreeModel.H"

TreeModel::TreeModel(QList<QVariant> data, QObject *parent) : QAbstractItemModel( parent ) {
    m_rootItem = new TreeItem(data);
}


TreeModel::~TreeModel() {
    //if( m_rootItem )
     //   delete m_rootItem;
}


QVariant TreeModel::data(const QModelIndex &index, int role) const {
    if( index.isValid() && role == Qt::DisplayRole ) {
        TreeItem *item = getItem( index );
        return item->data(index.column());
    }
    else {
        return QVariant();
    }
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const  {
    if( orientation == Qt::Horizontal && role == Qt::DisplayRole )
        return m_rootItem->data(section);
    else
        return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const  {
    if( parent.isValid()  && parent.column() != 0 ){
        return QModelIndex();
    }
    TreeItem *parentItem = getItem( parent );
    TreeItem *child = parentItem->child(row);
    if( child )
        return createIndex( row, column, child );
    else
        return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const  {
    if( !index.isValid() )
        return QModelIndex();
    TreeItem *child = getItem( index );
    TreeItem *parent = child->parent();
    if( parent == m_rootItem )
        return QModelIndex();
    else
        return createIndex( parent->childNumber(), 0, parent );
}


int TreeModel::rowCount(const QModelIndex &parent) const  {
    TreeItem *parentItem = getItem( parent );
    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent ) const  {
    Q_UNUSED( parent );
    return m_rootItem->columnCount();
}


Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const  {
    if( !index.isValid() )
        return 0;
    else
        return QAbstractItemModel::flags( index );
}

TreeItem* TreeModel::getItem( const QModelIndex &index ) const {
    if( index.isValid()) {
        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        if( item )
            return item;
    }
    return m_rootItem;

}
