#include "DataSet.H"

#include <QDate>
#include <QDebug>
#include <QString>
#include <QDateTime>

DataSet::DataSet(QTreeWidget *treeWidget, QObject *parent) : QObject(parent) {
    appendToLog("Initiated Class");
    m_treeWidget = treeWidget;
}

DataSet::~DataSet(){
    delete m_population;
}

void DataSet::addPopulation( Population *population ) {

    // set the population
    m_population = population;

    QString msg = QString("Load population with %1 individuals.").arg(m_population->count());
    appendToLog( msg );

    QTreeWidgetItem *itm = new QTreeWidgetItem( m_treeWidget, TREE_OBJECT_TYPE_GENOTYPES );
    itm->setText(0,tr("Genotypes"));
    itm->setSelected( true );
    AnalysisObject *obj = new AnalysisObject(itm, TREE_OBJECT_TYPE_GENOTYPES );
    m_analysisObjects.append( obj );
}


void DataSet::appendToLog( QString msg ) {
    QString now = QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODateWithMs);
    m_log = QString("%1[%2]: %3\n").arg( m_log ).arg(now).arg( msg );
}
