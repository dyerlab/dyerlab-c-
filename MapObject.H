#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "ResultObject.H"
#include "Population.H"

#include <QString>
#include <QWebEngineView>

class MapObject : public ResultObject
{
public:
    MapObject(Population *population, QTreeWidgetItem *item, TREE_OBJECT_TYPE type = TREE_OBJECT_TYPE_MAP);

private:
    QString m_htmlHeader;
    QString m_htmlFooter;
};

#endif // MAPOBJECT_H
