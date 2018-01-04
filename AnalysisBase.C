#include "AnalysisBase.H"

#include <QString>
#include <QDialog>
#include <QApplication>
#include <QInputDialog>

AnalysisBase::AnalysisBase(DataSet *data) {
    m_dataSet = data;
    m_analysisName = "AnalysisBase";
}



QString AnalysisBase::selectStratum() {

    return "";

}

QString AnalysisBase::selectLocus() {

    return "";

}
