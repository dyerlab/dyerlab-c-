#ifndef GRAPH2DOBJECT_H
#define GRAPH2DOBJECT_H

#include "ResultObject.H"


class Graph2DObject : public ResultObject
{
public:
    Graph2DObject(QTreeWidgetItem *item, TREE_OBJECT_TYPE type = TREE_OBJECT_TYPE_UNDEF);
};

#endif // GRAPH2DOBJECT_H
