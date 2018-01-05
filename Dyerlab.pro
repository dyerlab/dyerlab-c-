#-------------------------------------------------
#
# Project created by QtCreator 2017-12-27T15:53:16
#
#-------------------------------------------------

QT       += core gui webenginewidgets positioning

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dyerlab
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.C \
        MainWindow.C \
    Individual.C \
    Locus.C \
    FileIO.C \
    Population.C \
    DataSet.C \
    LogWindow.C \
    TableModel.C \
    AnalysisBase.C \
    AlleleFrequencies.C \
    Frequencies.C \
    ResultObject.C \
    GeneticObject.C \
    MapObject.C \
    JsonOps.C

HEADERS += \
        MainWindow.H \
    Individual.H \
    Locus.H \
    FileIO.H \
    Population.H \
    DataSet.H \
    LogWindow.H \
    TableModel.H \
    AnalysisBase.H \
    AlleleFrequencies.H \
    Frequencies.H \
    ResultObject.H \
    GeneticObject.H \
    MapObject.H \
    JsonOps.H

mac {

OBJECTIVE_SOURCES += \
    UnifiedWindow.mm
HEADERS  +=\
    UnifiedWindow.h


LIBS += -framework Foundation -framework Cocoa
}

FORMS +=

DISTFILES +=

RESOURCES += \
    data.qrc \
    styles.qrc
