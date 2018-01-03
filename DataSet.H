#ifndef DATASET_H
#define DATASET_H

#include <QObject>
#include <QTreeWidgetItem>

#include "TreeItem.H"
#include "TreeModel.H"
#include "Population.H"

typedef enum {
    TREE_WIDGET_TYPE_FOLDER,
    TREE_WIDGET_TYPE_GENOTYPES,
    TREE_WIDGET_TYPE_WEB,
    TREE_WIDGET_TYPE_MAP,
    TREE_WIDGET_TYPE_TEXT
} TREE_WIDGET_TYPE;

class DataSet : public QObject
{
    Q_OBJECT
public:
    explicit DataSet(QObject *parent = nullptr);
    ~DataSet();

    void addComponents( Population *population, QTreeWidget *treeWidget );

    inline Population* getPopulation() const                { return m_population; }
    inline Individual* getIndividual( int idx ) const       { return m_population->getIndividual( idx ); }
    inline QVariant getData( int idx, QString key) const    { return getIndividual(idx)->getData(key); }

    void appendToLog( QString msg );
    inline QString getLog() const                           { return m_log; }

signals:

public slots:


private:
    QString m_log;
    Population *m_population;
    QTreeWidgetItem *m_widgetItem;


};

#endif // DATASET_H
