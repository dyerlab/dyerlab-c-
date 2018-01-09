#ifndef DATASET_H
#define DATASET_H

#include <QList>
#include <QObject>
#include <QStackedWidget>
#include <QTreeWidgetItem>

#include "TreeItem.H"
#include "TreeModel.H"
#include "Population.H"
#include "ResultObject.H"


class DataSet : public QObject
{
    Q_OBJECT
public:
    explicit DataSet(QTreeWidget *treeWidget, QStackedWidget *stackedWidget, QObject *parent = nullptr);
    ~DataSet();

    bool loadPopulation( QString path, int strata, int coords, int loci );
    Population* getPopulation();

    bool makeMap();

    bool getAllFrequencies();

    void setNewObject( ResultObject *obj );
    void appendToLog( QString msg );
    inline QString getLog() const             { return m_log; }

signals:

public slots:
    void treeWidgetChanged( QTreeWidgetItem *current, QTreeWidgetItem *previous);


private:
    QString m_log;
    QTreeWidget *m_treeWidget;
    QStackedWidget *m_stackedWidget;
    QList<ResultObject*> m_resultObjects;

};

#endif // DATASET_H
