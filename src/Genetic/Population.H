#ifndef POPULATION_H
#define POPULATION_H

#include "Locus.H"
#include "Individual.H"


class Population
{
public:
    Population();
    ~Population();

    inline void addIndivdiual( Individual *val )    { m_inds.append( val ); }
    inline Individual* getIndividual( int idx )     { return m_inds.at(idx); }
    inline int count()                              { return m_inds.count(); }


private:

    QList<Individual*> m_inds;



};

#endif // POPULATION_H
