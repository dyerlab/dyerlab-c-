#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QDialog>
#include <QObject>
#include <QString>
#include <QTextEdit>
#include <QCloseEvent>
#include <QPushButton>
#include <QDialogButtonBox>


class LogWindow : public QDialog
{
    Q_OBJECT

public:
    LogWindow(QString msg, QWidget *parent = 0);


private:
    QTextEdit *m_textEdit;
    QDialogButtonBox *m_buttonBox;

};

#endif // LOGWINDOW_H
