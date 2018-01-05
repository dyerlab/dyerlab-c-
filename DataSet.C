#include "DataSet.H"
#include "FileIO.H"

#include "MapObject.H"
#include "GeneticObject.H"
#include "FrequencyObject.H"

#include <QDate>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QGeoCoordinate>

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
    m_treeWidget->selectionModel()->clearSelection();
    obj->getTreeWidgetItem()->setSelected(true);
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

bool DataSet::makeMap() {
    Population *thePop = getPopulation();
    if( !thePop )
        return false;
    QList<QGeoCoordinate*> coords;
    for(int i=0;i<thePop->count();i++){
        QGeoCoordinate *c = thePop->getIndividual(i)->getCoordinate();
        if( c->isValid() )
            coords.append( c );
    }
    if( !coords.count() )
        return false;

    //TODO: Add conversion to GeoJSON from
    QTreeWidgetItem *itm = new QTreeWidgetItem( m_treeWidget, TREE_OBJECT_TYPE_MAP );
    itm->setText(0,tr("Map"));

    MapObject *obj = new MapObject( getPopulation(), itm );
    setNewObject( obj );

    return true;
}



bool DataSet::getAllFrequencies() {

    QTreeWidgetItem *item = new QTreeWidgetItem( m_treeWidget, TREE_OBJECT_TYPE_FREQUENCIES );
    item->setText(0,"Allele Frequencies");

    FrequencyObject *obj = new FrequencyObject(getPopulation(), item );
    setNewObject( obj );
    return true;

}



Population* DataSet::getPopulation() {

    foreach(ResultObject *obj, m_resultObjects ){
        TREE_OBJECT_TYPE type = obj->objectType();
        if( type == TREE_OBJECT_TYPE_GENOTYPES ){
            GeneticObject *gen = static_cast<GeneticObject*>(obj);
            if( gen ) {
                return gen->getPopulation();
            }

        }
    }

    return NULL;
}




void DataSet::appendToLog( QString msg ) {
    QString now = QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODateWithMs);
    m_log = QString("%1[%2]: %3\n").arg( m_log ).arg(now).arg( msg );
}
