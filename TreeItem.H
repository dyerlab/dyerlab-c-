#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QString>
#include <QVariant>


class TreeItem
{
public:
    TreeItem( QList<QVariant> data, TreeItem *parent = 0 );
    ~TreeItem();

    inline TreeItem *child(int idx)             { return m_childItems.at(idx); }
    inline void appendChild( TreeItem *child )  { m_childItems.append( child ); }
    inline int childCount() const               { return m_childItems.count(); }
    inline int columnCount() const              { return m_itemData.count(); }
    inline QVariant data(int idx) const         { return m_itemData.at(idx); }
    inline TreeItem *parent()                   { return m_parent; }

    int childNumber() const;
    bool setData(int column, const QVariant &value);

private:
    QList<TreeItem*> m_childItems;
    QList<QVariant> m_itemData;
    TreeItem *m_parent;

};

#endif // TREEITEM_H
