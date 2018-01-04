#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "ResultObject.H"
#include "Population.H"

#include <QWebEngineView>

class MapObject : public ResultObject
{
public:
    MapObject(Population *population, QTreeWidgetItem *item, TREE_OBJECT_TYPE type = TREE_OBJECT_TYPE_MAP);


};

#endif // MAPOBJECT_H
