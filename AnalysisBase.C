#include "AnalysisBase.H"

#include <QString>
#include <QDialog>
#include <QApplication>
#include <QInputDialog>

AnalysisBase::AnalysisBase(DataSet *data) {
    m_dataSet = data;
    m_analysisName = "AnalysisBase";
}



QString AnalysisBase::selectStratum() {
    if( m_dataSet->getPopulation()->count() ) {
        Individual *ind = m_dataSet->getPopulation()->getIndividual(0);
        QStringList items = ind->getKeys(DATA_KEY_TYPE_STRATUM );
        items.push_front(QDialog::tr("Across All Data"));
        bool ok;
        QString ret = QInputDialog::getItem( qApp->activeWindow(),
                                             QDialog::tr("Select Stratum"),
                                             QDialog::tr("Stratum:"),
                                             items,
                                             0,
                                             false,
                                             &ok);
        if( ok && !ret.isEmpty() )
            return ret;
    }
    return "";

}

QString AnalysisBase::selectLocus() {
    if( m_dataSet->getPopulation()->count() ) {
        Individual *ind = m_dataSet->getPopulation()->getIndividual(0);
        QStringList items = ind->getKeys(DATA_KEY_TYPE_LOCUS );
        items.push_front(QDialog::tr("All Loci"));
        bool ok;
        QString ret = QInputDialog::getItem( qApp->activeWindow(),
                                             QDialog::tr("Select Locus"),
                                             QDialog::tr("Locus:"),
                                             items,
                                             0,
                                             false,
                                             &ok);
        if( ok && !ret.isEmpty() )
            return ret;
    }
    return "";

}
