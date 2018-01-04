#include "DataSet.H"
#include "FileIO.H"
#include "GeneticObject.H"

#include <QDate>
#include <QDebug>
#include <QString>
#include <QDateTime>

DataSet::DataSet(QTreeWidget *treeWidget, QStackedWidget *stackedWidget, QObject *parent) : QObject(parent) {

    appendToLog("Initiating Class");
    m_treeWidget = treeWidget;
    m_stackedWidget = stackedWidget;

}

DataSet::~DataSet(){
}

void DataSet::setNewObject( ResultObject *obj ) {
    m_stackedWidget->addWidget( obj->getWidget() );
    m_stackedWidget->setCurrentIndex( m_stackedWidget->indexOf( obj->getWidget() ) );
    m_resultObjects.append( obj );
}


bool DataSet::loadPopulation(QString path, int strata, int coords, int loci) {

    // set the population
    Population *population = loadIndividualsFromFile(path,strata,coords,loci);
    if( !population->count() ) {
        delete population;
        return false;
    }

    QString msg = QString("Load population with %1 individuals.").arg(population->count());
    appendToLog( msg );

    QTreeWidgetItem *itm = new QTreeWidgetItem( m_treeWidget, TREE_OBJECT_TYPE_GENOTYPES );
    itm->setText(0,tr("Genotypes"));
    itm->setSelected( true );
    GeneticObject *obj = new GeneticObject( population, itm );

    setNewObject( obj );
    return true;
}



void DataSet::appendToLog( QString msg ) {
    QString now = QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODateWithMs);
    m_log = QString("%1[%2]: %3\n").arg( m_log ).arg(now).arg( msg );
}
