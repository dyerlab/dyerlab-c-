#ifndef GENETICOBJECT_H
#define GENETICOBJECT_H

#include "Population.H"
#include "ResultObject.H"
#include "TableModel.H"

#include <QTableView>


class GeneticObject : public ResultObject  {

public:
    GeneticObject(Population *population, QTreeWidgetItem *item, TREE_OBJECT_TYPE type = TREE_OBJECT_TYPE_GENOTYPES);

    inline Population* getPopulation()      { return m_population; }

private:
    TableModel *m_tableModel;

};

#endif // GENETICOBJECT_H
