#include "TableModel.H"

#include <QBrush>
#include <QColor>

TableModel::TableModel(Population *population) {
    m_population = population;
    if( m_population->count() ) {
        Individual *ind = m_population->getIndividual(0);
        m_headers.append( ind->getKeys( DATA_KEY_TYPE_STRATUM ) );
        m_headers.append( ind->getKeys( DATA_KEY_TYPE_COORDINATE ) );
        m_headers.append( ind->getKeys( DATA_KEY_TYPE_LOCUS ) );
    }
}


int TableModel::rowCount(const QModelIndex &parent ) const {
    Q_UNUSED( parent );
    return m_population->count();
}

int TableModel::columnCount(const QModelIndex &parent ) const {
    Q_UNUSED( parent );
    return m_headers.count();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role ) const {
    if( role == Qt::DisplayRole ) {

        if( orientation == Qt::Horizontal )
            return QVariant( m_headers.at(section) );

        else if( orientation == Qt::Vertical )
            return QVariant( section );
    }
    else if( role == Qt::ForegroundRole && orientation == Qt::Horizontal && m_population->count() ) {
        QString key = m_headers.at(section);
        DATA_KEY_TYPE type = m_population->getIndividual(0)->getType( key );
        if( type == DATA_KEY_TYPE_LOCUS ) {
            return QVariant( QBrush( Qt::darkRed ) );
        }
        else if( type == DATA_KEY_TYPE_STRATUM ) {
            return QVariant( QBrush( Qt::darkGreen ) );
        }
        else if( type == DATA_KEY_TYPE_COORDINATE ) {
            return QVariant( QBrush( Qt::darkBlue ) );
        }
        else {
            return QVariant( QBrush( Qt::black ) );
        }
    }

    return QVariant();

}


QVariant TableModel::data(const QModelIndex &index, int role ) const {
    if( m_population->count() ) {
        int row = index.row();
        QString key = m_headers.at( index.column() );

        if( role == Qt::DisplayRole ) {
            return m_population->getIndividual(row)->getData( key );
        }
        else if( role == Qt::ForegroundRole ) {
            DATA_KEY_TYPE type = m_population->getIndividual(row)->getType( key );
            if( type == DATA_KEY_TYPE_LOCUS ) {
                return QVariant( QBrush( Qt::darkRed ) );
            }
            else if( type == DATA_KEY_TYPE_STRATUM ) {
                return QVariant( QBrush( Qt::darkGreen ) );
            }
            else if( type == DATA_KEY_TYPE_COORDINATE ) {
                return QVariant( QBrush( Qt::darkBlue ) );
            }
            else {
                return QVariant( QBrush( Qt::black ) );
            }
        }
        else if( role == Qt::TextAlignmentRole ){
            return QVariant( Qt::AlignCenter );
        }
    }
    return QVariant();
}

