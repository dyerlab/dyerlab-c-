#ifndef ANALYSISBASE_H
#define ANALYSISBASE_H

#include <QDebug>

#include "DataSet.H"

class AnalysisBase
{
public:
    AnalysisBase(DataSet *data);

    virtual void run() = 0;

    inline void setName( QString val )          { m_analysisName = val; }
    inline void setDescription( QString val)    { m_description = val;  }
    inline QString getLog() const               { return m_log; }

    QString selectStratum();
    QString selectLocus();



protected:
    DataSet *m_dataSet;
    QString m_analysisName;
    QString m_description;
    QString m_log;

};

#endif // ANALYSISBASE_H
