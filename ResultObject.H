#ifndef ANALYSISOBJECT_H
#define ANALYSISOBJECT_H

#include "Population.H"

#include <QFile>
#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextStream>
#include <QWebEngineView>
#include <QTreeWidgetItem>

typedef enum {
    TREE_OBJECT_TYPE_UNDEF,
    TREE_OBJECT_TYPE_FREQUENCIES,
    TREE_OBJECT_TYPE_GENOTYPES,
    TREE_OBJECT_TYPE_POPGRAPH,
    TREE_OBJECT_TYPE_FOLDER,
    TREE_OBJECT_TYPE_TEXT,
    TREE_OBJECT_TYPE_WEB,
    TREE_OBJECT_TYPE_MAP
} TREE_OBJECT_TYPE;

class ResultObject {

public:

    ResultObject(Population *population, QTreeWidgetItem *item, TREE_OBJECT_TYPE type = TREE_OBJECT_TYPE_UNDEF);
    ResultObject(QTreeWidgetItem *item, TREE_OBJECT_TYPE type = TREE_OBJECT_TYPE_UNDEF);

    inline QTreeWidgetItem* getTreeWidgetItem() { return m_treeWidgetItem; }
    inline TREE_OBJECT_TYPE objectType()        { return m_treeObjectType; }
    inline QWidget* getWidget()                 { return m_widget; }

protected:
    QWidget *m_widget;
    Population *m_population;
    QTreeWidgetItem *m_treeWidgetItem;
    TREE_OBJECT_TYPE m_treeObjectType;

};

#endif // ANALYSISOBJECT_H
