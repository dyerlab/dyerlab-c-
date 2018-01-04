#ifndef ANALYSISOBJECT_H
#define ANALYSISOBJECT_H

#include <QTreeWidgetItem>

typedef enum {
    TREE_OBJECT_TYPE_UNDEF,
    TREE_OBJECT_TYPE_FOLDER,
    TREE_OBJECT_TYPE_GENOTYPES,
    TREE_OBJECT_TYPE_WEB,
    TREE_OBJECT_TYPE_MAP,
    TREE_OBJECT_TYPE_TEXT
} TREE_OBJECT_TYPE;

class ResultObject {

public:

    ResultObject(QTreeWidgetItem *item, TREE_OBJECT_TYPE type = TREE_OBJECT_TYPE_UNDEF);

    inline TREE_OBJECT_TYPE objectType()        { return m_treeObjectType; }


protected:
    QTreeWidgetItem *m_treeWidgetItem;
    TREE_OBJECT_TYPE m_treeObjectType;

};

#endif // ANALYSISOBJECT_H
