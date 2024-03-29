#include "GeneticObject.H"

GeneticObject::GeneticObject(Population *population, QTreeWidgetItem *item, TREE_OBJECT_TYPE type ) :
    ResultObject(population, item, type)
{

    m_tableModel = new TableModel(m_population);
    QTableView *table = new QTableView();
    table->setModel(m_tableModel);
    m_widget = table;
    m_widget->setContentsMargins(0,0,0,0);
}
