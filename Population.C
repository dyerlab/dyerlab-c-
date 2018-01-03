#include "Population.H"

Population::Population()
{

}

Population::~Population() {
    for( int i=0;i<m_inds.count();i++)
        delete m_inds.at(i);
}
