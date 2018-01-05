#ifndef FREQUENCYOBJECT_H
#define FREQUENCYOBJECT_H

#include "ResultObject.H"
#include "Frequencies.H"


class FrequencyObject : public ResultObject
{
public:
    FrequencyObject(Population *population, QTreeWidgetItem *item, TREE_OBJECT_TYPE type = TREE_OBJECT_TYPE_FREQUENCIES);
};

#endif // FREQUENCYOBJECT_H
