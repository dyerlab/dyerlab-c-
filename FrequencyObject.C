#include "Charting.H"
#include "Frequencies.H"
#include "FrequencyObject.H"




FrequencyObject::FrequencyObject(Population *population, QTreeWidgetItem *item, TREE_OBJECT_TYPE type ) :
    ResultObject(population,item,type)
{

    QStringList loci = m_population->getIndividual(0)->getKeys(DATA_KEY_TYPE_LOCUS);
    loci.sort();

    if( !loci.count() )
        return;



    QWidget *mainWidget = new QWidget();

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainWidget->setLayout( mainLayout );

    foreach( QString locus, loci ) {
        Frequencies *freqs = new Frequencies(locus);
        if( freqs->grabFromPopulation(m_population, locus) ){

            QStringList alleles = freqs->getAlleles();
            alleles.sort();
            QList<double> values = freqs->getFrequencies( alleles );

            QChart *chart = makeBarChart(values,alleles,"Alleles","Frequency",locus);

            QChartView *view = new QChartView();
            view->setChart( chart );
            view->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            view->setRenderHint( QPainter::Antialiasing );
            mainLayout->addWidget( view );
        }
        else {
            qDebug() << "Unable to grab locus" << locus << "from population.";
        }
        delete freqs;
    }

    QScrollArea *scroller  = new QScrollArea();
    scroller->setWidget( mainWidget );
    scroller->setBackgroundRole( QPalette::Light );
    scroller->setSizeAdjustPolicy( QAbstractScrollArea::AdjustToContents );
    m_widget = scroller;
    m_widget->setContentsMargins(0,0,0,0);


}
