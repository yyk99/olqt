/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#include <ol/proj.h>
#include <ol/proj/projections.h>


ol::proj::Projection ol::proj::get(std::string const &projectionLike)
{
    std::string code = projectionLike;
    ol::proj::Projection projection = ol::proj::projections::get(code);
    //if (ol.ENABLE_PROJ4JS && !projection) {
    //  var proj4js = ol.proj.proj4.get();
    //  if (typeof proj4js == 'function' &&
    //      proj4js.defs(code) !== undefined) {
    //    projection = new ol.proj.Projection({code: code});
    //    ol.proj.addProjection(projection);
    //  }
    //}
    return projection;
}
