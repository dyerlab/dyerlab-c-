#include "MapObject.H"
#include "JsonOps.H"

#include <QFile>


MapObject::MapObject(Population *population, QTreeWidgetItem *item, TREE_OBJECT_TYPE type ) :
    ResultObject(population,item,type)
{
    QWebEngineView *view = new QWebEngineView();
    view->setObjectName("MapWebEngineView");


    if( m_population->count()) {
        QList<QGeoCoordinate*> coords;
        for(int i=0;i<m_population->count();i++){
            coords.append( m_population->getIndividual(i)->getCoordinate() );
        }
        QJsonObject json = geoCoordinateList2Json(coords);
        QJsonDocument doc(json);
        if( !doc.isEmpty() ) {
            QFile file("/Users/rodney/Desktop/test.json");
            if( file.open( QIODevice::WriteOnly ) ) {
                qDebug() << "writing";
                file.write(doc.toJson());
            }
            else {
                qDebug() << "Cannot open file";
            }
            file.close();

        }


    }



    /*

    Q_UNUSED(population);

    QFile file(":/data/leaflet.html");
    if( file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        QString page = stream.readAll();
        view->setHtml(page);
    }


    m_htmlHeader = QString("<!DOCTYPE html><html><head>"
                           "<title>Quick Start - Leaflet</title>"
                           "<meta charset=\"utf-8\" />"
                           "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
                           "<link rel=\"stylesheet\" href=\"https://unpkg.com/leaflet@1.2.0/dist/leaflet.css\" integrity=\"sha512-M2wvCLH6DSRazYeZRIm1JnYyh22purTM+FDB5CsyxtQJYeKq83arPe5wgbNmcFXGqiSH2XR8dT/fJISVA1r/zQ==\" crossorigin=\"\"/>"
                           "<script src=\"https://unpkg.com/leaflet@1.2.0/dist/leaflet.js\" integrity=\"sha512-lInM/apFSqyy1o6s89K4iQUKg6ppXEgsVxT35HbzUupEVRh2Eu9Wdl4tHj7dZO0s1uvplcYGmt3498TtHq+log==\" crossorigin=\"\"></script>"
                           "</head><body>"
                           "<div id=\"mapid\" style=\"width: 100%; height: 100%;\"></div>"
                           "<script>" );


    m_htmlFooter = QString("</script></body></html>");
*/

    m_widget = view;
    m_widget->setContentsMargins(0,0,0,0);
}
