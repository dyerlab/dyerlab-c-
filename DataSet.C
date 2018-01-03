#include "DataSet.H"

#include <QDate>
#include <QDebug>
#include <QString>
#include <QDateTime>

DataSet::DataSet(QObject *parent) : QObject(parent) {
    appendToLog("Initiated Class");
}

DataSet::~DataSet(){
    delete m_population;

}

void DataSet::addComponents( Population *population, QTreeWidget *treeWidget ) {

    // set the population
    m_population = population;
    QString msg = QString("Load population with %1 individuals.").arg(m_population->count());
    appendToLog( msg );

    // set the root TreeWidgetItem
    m_widgetItem = new QTreeWidgetItem( treeWidget, TREE_WIDGET_TYPE_GENOTYPES );
    m_widgetItem->setText(0,tr("Genotypes"));
    m_widgetItem->setSelected( true );

    QTreeWidgetItem *frequency_folder = new QTreeWidgetItem( treeWidget, TREE_WIDGET_TYPE_FOLDER);
    frequency_folder->setText(0,tr("Frequencies"));
    frequency_folder->setHidden(true);

    QTreeWidgetItem *diversity_folder = new QTreeWidgetItem( treeWidget, TREE_WIDGET_TYPE_FOLDER);
    diversity_folder->setText(0,tr("Diversity"));

    QTreeWidgetItem *distances_folder = new QTreeWidgetItem( treeWidget, TREE_WIDGET_TYPE_FOLDER);
    distances_folder->setText(0,tr("Distances"));

    QTreeWidgetItem *structure_folder = new QTreeWidgetItem( treeWidget, TREE_WIDGET_TYPE_FOLDER);
    structure_folder->setText(0,tr("Structure"));

    QTreeWidgetItem *maps_folder = new QTreeWidgetItem( treeWidget, TREE_WIDGET_TYPE_FOLDER);
    maps_folder->setText(0,tr("Maps"));

}


void DataSet::appendToLog( QString msg ) {
    QString now = QDateTime::currentDateTime().toLocalTime().toString(Qt::ISODateWithMs);
    m_log = QString("%1[%2]: %3\n").arg( m_log ).arg(now).arg( msg );
}
