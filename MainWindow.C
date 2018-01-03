#include "MainWindow.H"

#include "FileIO.H"

#include <QMenu>
#include <QMenuBar>
#include <QSettings>
#include <QHeaderView>
#include <QApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    makeActions();
    makeMenus();
    makeUI();
}

MainWindow::~MainWindow() {

}

void MainWindow::makeActions() {
    importAction = new QAction( tr("&Import"),this );
    importAction->setShortcut(tr("CTRL+I"));
    connect( importAction, SIGNAL(triggered(bool)), this, SLOT( slotImportAction()));

    showLogAction = new QAction( tr("&Log"), this);
    showLogAction->setShortcut(tr("CTRL+L") );
    connect( showLogAction, SIGNAL(triggered(bool)), this , SLOT( slotShowLog()) );

    quitAction = new QAction( tr("&Quit"), this);
    quitAction->setShortcut(tr("CTRL+Q"));
    connect( quitAction, SIGNAL( triggered(bool)), qApp, SLOT( quit()) );

}

void MainWindow::makeMenus() {
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction( importAction );
    fileMenu->addSeparator();
    fileMenu->addAction( quitAction );

    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction( showLogAction );
}

void MainWindow::makeUI() {
    mainSplitter = new QSplitter(this);
    setCentralWidget(mainSplitter);

    treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(1);
    treeWidget->header()->hide();
    treeWidget->setAttribute(Qt::WA_MacShowFocusRect, 0);
    //treeWidget->header()->hide();

    stackedWidget = new QStackedWidget();
    tableView = new QTableView();
    stackedWidget->addWidget( tableView );

    webEngineView = new QWebEngineView();
    stackedWidget->addWidget( webEngineView );
    stackedWidget->setCurrentIndex(0);

    mainSplitter->addWidget( treeWidget );
    mainSplitter->addWidget( stackedWidget );

    QSettings settings("Dyerlab","Dyerlab");
    restoreGeometry( settings.value("geometry").toByteArray() );
    restoreState( settings.value("windowState").toByteArray() );
    mainSplitter->restoreState( settings.value("splitterState").toByteArray());
}

void MainWindow::closeEvent(QCloseEvent *event) {
    QSettings settings("Dyerlab","Dyerlab");
    settings.setValue("geometry", saveGeometry() );
    settings.setValue("windowState", saveState() );
    settings.setValue("splitterState", mainSplitter->saveState() );

    QMainWindow::closeEvent( event );
}



void MainWindow::slotImportAction() {
    QString path  = ":/data/pedima_baja.csv";

    // Make the new data set
    m_dataSet = new DataSet();
    m_dataSet->addComponents( loadIndividualsFromFile(path, 1, 2, 6 ), treeWidget );

    // connect the table model to the table;
    m_tableModel = new TableModel( m_dataSet->getPopulation() );
    m_dataSet->appendToLog("Setting TableModel");
    tableView->setModel( m_tableModel );

    // connect the TreeView up
    //m_treeModel = m_dataSet->getTreeModel();
    //treeView->setModel( m_treeModel );

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
