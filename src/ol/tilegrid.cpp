/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#include "tilegrid.h"
#include <algorithm>
#include <cmath>

ol::tilegrid::TileGrid OLQT_EXPORT ol::tilegrid::createForExtent(ol::Extent const &extent, int opt_maxZoom /*= ol::DEFAULT_MAX_ZOOM*/, ol::Size const &opt_tileSize /*= ol::Size()*/, ol::extent::Corner::enum_t opt_corner /*= extent::Corner::TOP_LEFT*/)
{
    ////ol.tilegrid.createForExtent = function(extent, opt_maxZoom, opt_tileSize, opt_corner) {
    //var corner = opt_corner != = undefined ?
    //    opt_corner : ol.extent.Corner.TOP_LEFT;

    auto resolutions = ol::tilegrid::resolutionsFromExtent(
        extent, opt_maxZoom, opt_tileSize);

    //return new ol.tilegrid.TileGrid({
    //  extent: extent,
    //  origin : ol.extent.getCorner(extent, corner),
    //  resolutions : resolutions,
    //  tileSize : opt_tileSize
    //});

    ol::tilegrid::TileGrid::Options options;
    options.extent = extent;
    options.origin = ol::extent::getCorner(extent, opt_corner);

    return ol::tilegrid::TileGrid(resolutions, options);
}

ol::resolutions_t OLQT_EXPORT ol::tilegrid::resolutionsFromExtent(ol::Extent const &extent, 
    int opt_maxZoom /*= ol::DEFAULT_MAX_ZOOM*/, 
    ol::Size const &opt_tileSize /*= ol::Size()*/)
{
    //ol.tilegrid.resolutionsFromExtent = function(extent, opt_maxZoom, opt_tileSize) {
    int maxZoom = opt_maxZoom;

    number_t height = ol::extent::getHeight(extent);
    number_t width = ol::extent::getWidth(extent);

    ol::Size tileSize = opt_tileSize.size() ? opt_tileSize : ol::Size(2, ol::DEFAULT_TILE_SIZE);
    number_t maxResolution = std::max<number_t>(width / tileSize[0], height / tileSize[1]);

    size_t length = maxZoom + 1;
    ol::resolutions_t resolutions (length);
    for (int z = 0; z != length; ++z) {
        resolutions[z] = maxResolution / std::pow(2, z);
    }
    return resolutions;
}
