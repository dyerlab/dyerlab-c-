#ifndef FREQUENCIES_H
#define FREQUENCIES_H

#include <QHash>
#include <QString>

#include "Locus.H"

class Frequencies
{
public:
    Frequencies(QString name);

    void addLocus( Locus *loc );
    double getFrequency( QString allele );
    QList<double> getFrequencies( QStringList alleles );
    inline QStringList getAlleles()                         { return m_counts.keys(); }

    double getHo();
    double hetHe();

private:
    QString m_label;
    double m_N;
    double m_Nhets;
    double m_Ngenos;
    QHash<QString,double> m_counts;

};

#endif // FREQUENCIES_H
