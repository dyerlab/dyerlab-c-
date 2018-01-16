#include "ResultObject.H"

ResultObject::ResultObject(Population *population, QTreeWidgetItem *item, TREE_OBJECT_TYPE type ) {
    m_population = population;
    m_treeWidgetItem = item;
    m_treeObjectType = type;
}


ResultObject::ResultObject(QTreeWidgetItem *item, TREE_OBJECT_TYPE type) {
    m_treeWidgetItem = item;
    m_treeObjectType = type;
}
