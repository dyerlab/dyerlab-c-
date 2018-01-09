#include "LogWindow.H"
#include <QVBoxLayout>

LogWindow::LogWindow(QString msg , QWidget *parent) : QDialog( parent ) {
    m_textEdit = new QTextEdit(this);
    m_textEdit->setText( msg );
    m_textEdit->setReadOnly(true);

    m_buttonBox = new QDialogButtonBox( QDialogButtonBox::Ok );

    connect( m_buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked(bool)), this, SLOT(accept()));

    QVBoxLayout *mainLayout = new QVBoxLayout( this );
    mainLayout->addWidget( m_textEdit );
    mainLayout->addWidget(m_buttonBox);

    this->setLayout( mainLayout );
    this->setWindowTitle("Dyerlab log file");

}




