#include "Charting.H"

#include <QBarSet>

QChart* makeBarChart( QList<double> values, QStringList labels, QString xlab, QString ylab, QString title) {
    QBarSet *set = new QBarSet("Alleles");
    foreach( double val, values )
        *set << val;
    QBarSeries *series = new QBarSeries();
    series->append( set );

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle( title );

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->setTitleText(xlab);
    axisX->append(labels);
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText(ylab);

    chart->setAxisX( axisX, series);
    chart->setAxisY( axisY, series );
    axisY->setRange(0,1.0);

    return chart;
}
