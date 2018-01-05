/******************************************************************************
*                       _                 _       _
*                    __| |_   _  ___ _ __| | __ _| |__
*                   / _` | | | |/ _ \ '__| |/ _` | '_ \
*                  | (_| | |_| |  __/ |  | | (_| | |_) |
*                   \__,_|\__, |\___|_|  |_|\__,_|_.__/
*                         |___/
*
*  CoordinateTransformations.H
*
*  Created: 1 2018 by rodney
*
*  Copyright 2018 rodney.  All Rights Reserved.
*
* This file may be distributed under the terms of GNU Public License version
* 3 (GPL v3) as defined by the Free Software Foundation (FSF). A copy of the
* license should have been included with this file, or the project in which
* this file belongs to. You may also find the details of GPL v3 at:
*
* http://www.gnu.org/licenses/gpl-3.0.txt
*
* If you have any questions regarding the use of this file, feel free to
* contact the author of this file, or the owner of the project in which
* this file belongs to.
*
******************************************************************************/

#ifndef JSONOPERATIONS_H
#define JSONOPERATIONS_H

#include <QList>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QGeoCoordinate>


QJsonObject geoCoordinate2Json( QGeoCoordinate *coord );
QJsonObject geoCoordinateList2Json( QList<QGeoCoordinate*> coords );




#endif // JSONOPERATIONS_H
