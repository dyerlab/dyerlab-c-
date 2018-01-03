#include "MainWindow.H"
#include "UnifiedWindow.h"

#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

#ifdef Q_OS_MACOS
    // makes window look modern.
    UnifiedWindow::HideTitleBar( w.winId() );
#endif

    w.show();
    return a.exec();
}
