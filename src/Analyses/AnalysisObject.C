#include "AnalysisObject.H"

AnalysisObject::AnalysisObject(QTreeWidgetItem *item, TREE_OBJECT_TYPE type ) {
    m_treeWidgetItem = item;
    m_treeObjectType = type;
}
