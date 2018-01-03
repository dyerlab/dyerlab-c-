#ifndef LOCUS_H
#define LOCUS_H

#include <QString>
#include <QStringList>

class Locus
{
public:
    Locus( QStringList vals = QStringList());

    inline QString toString()       { return m_alleles.join(":"); }
    inline int ploidy()             { return m_alleles.count(); }
    inline bool isEmpty()           { return ploidy() == 0; }
    inline QStringList alleles()    { return m_alleles; }

    bool isHeterozygote();

private:
    QStringList m_alleles;
};

#endif // LOCUS_H
