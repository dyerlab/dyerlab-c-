#include "MapObject.H"

MapObject::MapObject(Population *population, QTreeWidgetItem *item, TREE_OBJECT_TYPE type ) :
    ResultObject(item,type)
{
    QWebEngineView *view = new QWebEngineView();



    m_widget = view;
}
