#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "Locus.H"

#include <QHash>
#include <QString>
#include <QVariant>
#include <QStringList>
#include <QGeoCoordinate>

typedef enum {
    DATA_KEY_TYPE_UNDEF,
    DATA_KEY_TYPE_ALL,
    DATA_KEY_TYPE_STRATUM,
    DATA_KEY_TYPE_COORDINATE,
    DATA_KEY_TYPE_LOCUS
} DATA_KEY_TYPE;

class Individual
{
public:
    Individual();
    ~Individual();

    inline void addLocus( QString key, Locus *val )         { m_loci[key] = val; }
    inline Locus* getLocus( QString key)                    { return m_loci[key]; }
    inline void addStratum( QString key, QString val  )     { m_strata[key] = val; }
    inline QString getStratum( QString key )                { return m_strata[key]; }
    inline void addCoordinate( QGeoCoordinate val )         { m_coord = val; }
    inline QGeoCoordinate getCoordinate()                   { return m_coord; }

    QVariant getData( QString key );
    QStringList getKeys( DATA_KEY_TYPE type = DATA_KEY_TYPE_ALL );
    DATA_KEY_TYPE getType( QString key );

private:
    QHash<QString,QString> m_strata;
    QHash<QString, Locus*> m_loci;
    QGeoCoordinate m_coord;


};

#endif // INDIVIDUAL_H
