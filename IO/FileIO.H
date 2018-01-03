#ifndef FILEIO_H
#define FILEIO_H

#include "Individual.H"
#include "Population.H"

#include <QList>

Population* loadIndividualsFromFile(QString path , int strata, int coords, int loci);



#endif // FILEIO_H
