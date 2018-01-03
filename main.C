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
    QFile file(":/styles/macos_style.qss");
    if( file.open(QIODevice::ReadOnly )) {
        QTextStream stream(&file);
        QString styles = stream.readAll();
        qDebug() << "Styles";
        qDebug().noquote() << styles;
        qApp->setStyle(styles);
    }
    else {
        qDebug() << "Could not open file.";
    }
    file.close();
#endif

    w.show();
    return a.exec();
}
