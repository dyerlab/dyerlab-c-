#include "AlleleFrequencies.H"

AlleleFrequencies::AlleleFrequencies(DataSet *data) : AnalysisBase( data ) {
    m_analysisName = "Allele Frequencies";
}


void AlleleFrequencies::run() {
    QString stratum = selectStratum();
    if( stratum.isEmpty() )
        return;
}
