#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "DataSet.H"
#include "LogWindow.H"
#include "TableModel.H"

#include <QAction>
#include <QSplitter>
#include <QTableView>
#include <QCloseEvent>
#include <QTreeWidget>
#include <QMainWindow>
#include <QWebEngineView>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeEvent(QCloseEvent *event );


private:

    QAction *importGenotypeAction;
    QAction *showLogAction;
    QAction *quitAction;

    QSplitter *mainSplitter;
    QTreeWidget *treeWidget;
    QStackedWidget *stackedWidget;

    QTableView *tableView;
    QWebEngineView *webEngineView;

    DataSet *m_dataSet;
    LogWindow *m_logWindow;
    TableModel *m_tableModel;
    TreeModel *m_treeModel;

    void makeActions();
    void makeMenus();
    void makeUI();

    void enableMenuItems(bool enabled );


public slots:
    void slotImportGenotypes();
    void slotShowLog();

};

#endif // MAINWINDOW_H
