#ifndef DATASET_H
#define DATASET_H

#include <QList>
#include <QObject>
#include <QTreeWidgetItem>

#include "TreeItem.H"
#include "TreeModel.H"
#include "Population.H"
#include "AnalysisObject.H"


class DataSet : public QObject
{
    Q_OBJECT
public:
    explicit DataSet(QTreeWidget *treeWidget, QObject *parent = nullptr);
    ~DataSet();

    void addPopulation( Population *population );


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
    QTreeWidget *m_treeWidget;
    QList<AnalysisObject*> m_analysisObjects;

};

#endif // DATASET_H
