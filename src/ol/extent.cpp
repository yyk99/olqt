/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#include "extent.h"

ol::Coordinate OLQT_EXPORT ol::extent::getTopLeft(ol::Extent const &ex)
{
    //ol.extent.getTopLeft = function(extent) {
    //  return [extent[0], extent[3]];
    ol::Coordinate coord(2);
    coord[0] = ex[0];
    coord[1] = ex[3];

    return coord;
}

