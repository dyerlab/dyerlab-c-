#include "Frequencies.H"

Frequencies::Frequencies(QString name) {
    m_label = name;
    m_N = m_Ngenos = m_Nhets = 0.0;
}

bool Frequencies::grabFromPopulation( Population *population, QString key ) {
    int N = population->count();
    if( !N )
        return false;
    for(int i=0;i<N;i++){
        addLocus( population->getIndividual(i)->getLocus(key));
    }
    return true;
}

void Frequencies::addLocus( Locus *loc ) {
    QStringList alleles = loc->alleles();
    foreach( QString allele, alleles ){
        if( m_counts.contains(allele))
            m_counts[allele] = m_counts[allele] + 1.0;
        else
            m_counts[allele] = 0.0;
        m_N++;
    }
    if( alleles.count() > 1 ) {
        m_Ngenos++;
        if( loc->isHeterozygote() )
            m_Nhets++;
    }
}

double Frequencies::getFrequency( QString allele ) {
    if( m_N > 0 ) {
        return m_counts.value(allele,0.0) / m_N;
    }
    else {
        return 0.0;
    }
}

QList<double> Frequencies::getFrequencies( QStringList alleles ) {
    QList<double> ret;
    foreach( QString allele, alleles ){
        ret << getFrequency(allele);
    }
    return ret;
}

double Frequencies::getHo() {
    if( m_Ngenos )
        return m_Nhets / m_Ngenos;
    else
        return 0.0;
}

double Frequencies::hetHe() {
    QList<double> freqs = getFrequencies( getAlleles() );
    double ret = 0.0;
    foreach( double freq, freqs )
        ret += freq * freq;
    return 1.0 - ret;
}
