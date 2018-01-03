#include "TreeItem.H"

TreeItem::TreeItem(QList<QVariant> data, TreeItem *parent) {
    m_itemData = data;
    m_parent = parent;
}


TreeItem::~TreeItem() {
    qDeleteAll( m_childItems );
}


int TreeItem::childNumber() const {
    if( m_parent )
        return m_parent->m_childItems.indexOf( const_cast<TreeItem*>(this));
    else
        return 0;
}

bool TreeItem::setData(int column, const QVariant &value) {
    if( column < m_itemData.count() || column < 0 ) {
        return false;
    }
    else {
        m_itemData[column] = value;
        return true;
    }
}

