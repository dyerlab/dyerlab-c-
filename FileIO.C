#include "FileIO.H"

#include <QFile>
#include <QDebug>
#include <QTextStream>

Population* loadIndividualsFromFile( QString path, int strata, int coords, int loci ) {
    Population *thePop = new Population();
    QFile file(path);
    if( file.open(QIODevice::ReadOnly) ){
        QTextStream stream(&file);
        QStringList header = stream.readLine().split(",");
        Q_ASSERT( header.count() == strata+coords+loci);

        while( !stream.atEnd() ){
            QStringList row = stream.readLine().split(",");
            if( row.count() == header.count() ){
                Individual *ind = new Individual();
                int ctr = 0;
                for( int i=0;i<strata;i++){
                    ind->addStratum(header[i],row[i]);
                    ctr++;
                }
                if( coords ){
                    double lat=0;
                    double lon=0;

                    int idx = header.indexOf("Longitude");
                    if( idx != -1 )
                        lon = row.at(idx).toDouble();
                    idx = header.indexOf("Latitude");
                    if( idx != -1 )
                        lat = row.at(idx).toDouble();
                    QGeoCoordinate coord(lat,lon);
                    if( coord.isValid()) {
                        ind->addCoordinate(coord);
                        ctr+=2;
                    }
                }
                for( int i = ctr; i<row.count(); i++) {
                    QStringList vals = row.at(i).split(":");
                    Locus *loc = new Locus( vals );
                    ind->addLocus( header.at(i), loc );
                }
                thePop->addIndivdiual( ind );
            }
        }
    }
    else {
        qDebug() << "Unable to open file.";
    }
    file.close();

    return thePop;
}
