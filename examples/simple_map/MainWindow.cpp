/*
 * Copyright (C) 2017 
 * All rights reserved.
 *
 */

#include "MainWindow.h"

#include <ol/Map.h>
#include <ol/View.h>
#include <ol/layer/Tile.h>
#include <ol/source/OSM.h>

/*
<!DOCTYPE html>
<html>
  <head>
    <title>Simple Map</title>
    <link rel="stylesheet" href="https://openlayers.org/en/v4.6.4/css/ol.css" type="text/css">
    <!-- The line below is only needed for old environments like Internet Explorer and Android 4.x -->
    <script src="https://cdn.polyfill.io/v2/polyfill.min.js?features=requestAnimationFrame,Element.prototype.classList,URL"></script>
    <script src="https://openlayers.org/en/v4.6.4/build/ol.js"></script>
  </head>
  <body>
    <div id="map" class="map"></div>
    <script>
      var map = new ol.Map({
        layers: [
          new ol.layer.Tile({
            source: new ol.source.OSM()
          })
        ],
        target: 'map',
        view: new ol.View({
          center: [0, 0],
          zoom: 2
        })
      });
    </script>
  </body>
</html>
*/

MainWindow::MainWindow(QWindow *parent /*= 0*/)
{
    m_map = ol::MapPtr(new ol::Map);
    
    auto tile = new ol::layer::Tile(/*source: */new ol::source::OSM());
    m_map->addLayer(tile);
    auto view = new ol::View();
    m_map->setView(view);

    m_map->setTarget("this window");
}

MainWindow::~MainWindow()
{

}

// end of file
