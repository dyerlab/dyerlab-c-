#include "Locus.H"

Locus::Locus( QStringList vals ) {
    m_alleles = vals;
}


bool Locus::isHeterozygote() {
    QStringList a = m_alleles;
    a.removeDuplicates();

    return (a.count() > 1);
}
