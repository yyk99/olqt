/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#include "extent.h"

ol::Extent OLQT_EXPORT ol::extent::createOrUpdate(double minX, double minY, double maxX, double maxY)
{
    //ol.extent.createOrUpdate = function(minX, minY, maxX, maxY, opt_extent) {
    //  if (opt_extent) {
    //    opt_extent[0] = minX;
    //    opt_extent[1] = minY;
    //    opt_extent[2] = maxX;
    //    opt_extent[3] = maxY;
    //    return opt_extent;
    //  } else {
    //    return [minX, minY, maxX, maxY];
    //  }
    return ol::Extent({ minX, minY, maxX, maxY });
}

ol::number_t OLQT_EXPORT ol::extent::getEnlargedArea(ol::Extent const &extent1, ol::Extent const &extent2)
{
    //ol.extent.getEnlargedArea = function(extent1, extent2) {
    //  var minX = Math.min(extent1[0], extent2[0]);
    //  var minY = Math.min(extent1[1], extent2[1]);
    //  var maxX = Math.max(extent1[2], extent2[2]);
    //  var maxY = Math.max(extent1[3], extent2[3]);
    //  return (maxX - minX) * (maxY - minY);
    //};
    throw std::runtime_error("Not implemented");
}

double OLQT_EXPORT ol::extent::getHeight(ol::Extent const &extent)
{
    return extent[3] - extent[1];
}

ol::Coordinate OLQT_EXPORT ol::extent::getTopLeft(ol::Extent const &ex)
{
    //ol.extent.getTopLeft = function(extent) {
    //  return [extent[0], extent[3]];
    ol::Coordinate coord(2);
    coord[0] = ex[0];
    coord[1] = ex[3];

    return coord;
}

ol::number_t OLQT_EXPORT ol::extent::getWidth(ol::Extent const &extent)
{
    return extent[2] - extent[0];
}

ol::Coordinate ol::extent::getBottomLeft(ol::Extent const & extent)
{
    //  return [extent[0], extent[1]];
    return ol::Coordinate({ extent[0], extent[1] });
}

ol::Coordinate ol::extent::getBottomRight(ol::Extent const & extent)
{
    //  return [extent[2], extent[1]];
    return ol::Coordinate({ extent[2], extent[1] });
}

ol::Coordinate ol::extent::getTopRight(ol::Extent const & extent)
{
    //ol.extent.getTopRight = function(extent) {
    //  return [extent[2], extent[3]];
    return ol::Coordinate({ extent[2], extent[3] });
}

//ol.extent.getCorner = function(extent, corner) {
ol::Coordinate OLQT_EXPORT ol::extent::getCorner(ol::Extent const &extent, Corner::enum_t corner)
{
    ol::Coordinate coordinate;
    if (corner == ol::extent::Corner::BOTTOM_LEFT) {
        coordinate = ol::extent::getBottomLeft(extent);
    } else if (corner == ol::extent::Corner::BOTTOM_RIGHT) {
        coordinate = ol::extent::getBottomRight(extent);
    } else if (corner == ol::extent::Corner::TOP_LEFT) {
        coordinate = ol::extent::getTopLeft(extent);
    } else if (corner == ol::extent::Corner::TOP_RIGHT) {
        coordinate = ol::extent::getTopRight(extent);
    } else {
        // ol.asserts.assert(false, 13); // Invalid corner
        throw std::runtime_error("13 - invalid corner");
    }
    return /** @type {!ol.Coordinate} */ (coordinate);
};

