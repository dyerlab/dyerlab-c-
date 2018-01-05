#ifndef CHARTING_H
#define CHARTING_H

#include <QtCharts>

using namespace QtCharts;

QChart* makeBarChart(QList<double> values, QStringList labels, QString xlab, QString ylab, QString title);


#endif // CHARTING_H
