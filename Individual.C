#include "Individual.H"

Individual::Individual() {
}

Individual::~Individual() {
    foreach( Locus *loc, m_loci.values() )
        delete loc;
}

QVariant Individual::getData( QString key ) {
    if( m_strata.keys().contains(key) )
        return QVariant( m_strata[key] );
    else if (m_loci.keys().contains(key))
        return QVariant( m_loci[key]->toString());
    else if( QString::compare(key,"Longitude", Qt::CaseInsensitive))
        return QVariant( m_coord->longitude());
    else if( QString::compare(key, "Latitude", Qt::CaseInsensitive))
        return QVariant( m_coord->latitude());
    else
        return QVariant();
}


QStringList Individual::getKeys( DATA_KEY_TYPE type ) {
    QStringList ret;

    if( type == DATA_KEY_TYPE_COORDINATE ) {
        ret << "Longitude" << "Latitude" ;
    }
    else if( type == DATA_KEY_TYPE_STRATUM) {
        ret = m_strata.keys();
    }
    else if( type == DATA_KEY_TYPE_LOCUS ) {
        ret << m_loci.keys();
    }

    ret.sort();
    return ret;
}

DATA_KEY_TYPE Individual::getType( QString key ) {
    if( m_strata.keys().contains(key))
        return DATA_KEY_TYPE_STRATUM;
    else if( m_loci.keys().contains( key ))
        return DATA_KEY_TYPE_LOCUS;
    else if( QString::compare( key, "Longitude", Qt::CaseInsensitive))
        return DATA_KEY_TYPE_COORDINATE;
    else if( QString::compare( key, "Latitude", Qt::CaseInsensitive))
        return DATA_KEY_TYPE_COORDINATE;
    else
        return DATA_KEY_TYPE_UNDEF;
}

