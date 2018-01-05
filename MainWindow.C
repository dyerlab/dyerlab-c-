#include "MainWindow.H"

#include "FileIO.H"

#include <QMenu>
#include <QFrame>
#include <QDialog>
#include <QMenuBar>
#include <QSettings>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    makeActions();
    makeMenus();
    makeUI();

    loadSettings();
}

MainWindow::~MainWindow() {
}

void MainWindow::saveSettings() {

    QSettings settings("dyerlab","dlab");
    settings.setValue("mainwindow/size", size() );
    settings.setValue("mainwindow/position", pos() );
    settings.setValue("splitter/state", mainSplitter->saveState() );

    qDebug() << "Saving settings";
}


void MainWindow::loadSettings() {

    QSettings settings("dyerlab","dlab");
    resize( settings.value( "mainwindow/size", QSize(600,400)).toSize());
    move( settings.value( "mainwindow/position", QPoint(200,200)).toPoint() );
    mainSplitter->restoreState( settings.value("smplitter/state","").toByteArray() );

    qDebug() << "Loading settings";
}

void MainWindow::makeActions() {
    importGenotypeAction = new QAction( tr("&Genotypes"),this );
    importGenotypeAction->setShortcut(tr("CTRL+G"));
    connect( importGenotypeAction, SIGNAL(triggered(bool)), this, SLOT( slotImportGenotypes()));

    makeMapAction = new QAction( tr("Create"));
    makeMapAction->setShortcut(tr("CTRL+M"));
    makeMapAction->setEnabled(false);
    connect( makeMapAction, SIGNAL( triggered(bool)), this, SLOT( slotMakeMap()) );

    showLogAction = new QAction( tr("&Log"), this);
    showLogAction->setShortcut(tr("CTRL+L") );
    connect( showLogAction, SIGNAL(triggered(bool)), this , SLOT( slotShowLog()) );

    quitAction = new QAction( tr("&Quit"), this);
    quitAction->setShortcut(tr("CTRL+Q"));
    connect( quitAction, SIGNAL( triggered(bool)), this, SLOT( slotQuit())  );

}

void MainWindow::makeMenus() {
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QMenu *importMenu = fileMenu->addMenu( tr("&Import") );
    importMenu->addAction( importGenotypeAction );

    fileMenu->addMenu( importMenu );
    fileMenu->addSeparator();
    fileMenu->addAction( quitAction );

    QMenu *mapMenu = menuBar()->addMenu(tr("&Map"));
    mapMenu->addAction(makeMapAction);

    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction( showLogAction );
}

void MainWindow::makeUI() {
    mainSplitter = new QSplitter(this);
    mainSplitter->setFrameStyle(QFrame::NoFrame);

    setCentralWidget(mainSplitter);

    QWidget *treeMainWidget = new QWidget();
    treeMainWidget->setObjectName("TreeMainWidget");
    QVBoxLayout *treeLayout = new QVBoxLayout();
    treeLayout->setContentsMargins(0,20,0,0);
    treeMainWidget->setLayout( treeLayout );
    //treeLayout->insertSpacing(0,20);
    treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(1);
    treeWidget->header()->hide();
    treeWidget->setAttribute(Qt::WA_MacShowFocusRect, 0);
    treeLayout->addWidget(treeWidget);

    QWidget *stackedMainWidget = new QWidget();
    stackedMainWidget->setObjectName("StackedWidgetWidget");
    QVBoxLayout *stackedLayout = new QVBoxLayout();
    stackedMainWidget->setLayout( stackedLayout );
    stackedLayout->insertSpacing(0,1);
    stackedWidget = new QStackedWidget();
    stackedLayout->addWidget( stackedWidget );

    mainSplitter->addWidget( treeMainWidget );
    mainSplitter->addWidget( stackedMainWidget );
    mainSplitter->setStretchFactor(1,100);
    mainSplitter->setStretchFactor(0,0);


    // make the data
    m_dataSet = new DataSet(treeWidget, stackedWidget, this);

    // set up some stylesheets
#ifdef Q_OS_MACOS
    QFile file(":/styles/macos_style.qss");
    if( file.open(QIODevice::ReadOnly )) {
        QTextStream stream(&file);
        QString styles = stream.readAll();
        this->setStyleSheet( styles );
    }
    else {
        qDebug() << "Could not open file.";
    }
    file.close();
#endif



}

void MainWindow::closeEvent(QCloseEvent *event) {
    //saveSettings();
    QMainWindow::closeEvent( event );
}

void MainWindow::enableMenuItems( bool enabled ){
    importGenotypeAction->setEnabled( !enabled );
    makeMapAction->setEnabled( enabled );
}









void MainWindow::slotImportGenotypes() {
    QString path  = ":/data/pedima_baja.csv";
    if( m_dataSet->loadPopulation( path, 1, 2, 6 ) ) {
        enableMenuItems(true);
    } else {
        QMessageBox dlg;
        dlg.setText(tr("Unable to import genotype file"));
        dlg.setIcon(QMessageBox::Warning);
        dlg.exec();
    }
}

void MainWindow::slotQuit() {
    saveSettings();
    qApp->quit();
}


void MainWindow::slotShowLog() {
    if( m_dataSet ) {
        m_logWindow = new LogWindow( m_dataSet->getLog(), this );
        m_logWindow->exec();
        delete m_logWindow;
    }
    else {
        qDebug() << "Nothing loaded yet";
    }

}

void MainWindow::slotMakeMap() {
    m_dataSet->makeMap();
}
