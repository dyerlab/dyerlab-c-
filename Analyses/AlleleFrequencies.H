#ifndef ALLELEFREQUENCIES_H
#define ALLELEFREQUENCIES_H

#include "AnalysisBase.H"

class AlleleFrequencies : public AnalysisBase
{
public:
    AlleleFrequencies(DataSet *data);

    void run();



};

#endif // ALLELEFREQUENCIES_H
