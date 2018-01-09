/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#ifndef OL_TILEGRID_H
#define OL_TILEGRID_H

// based on v4.6.4

//goog.provide('ol.tilegrid');
//
//goog.require('ol');
//goog.require('ol.size');
//goog.require('ol.extent');
//goog.require('ol.extent.Corner');
//goog.require('ol.obj');
//goog.require('ol.proj');
//goog.require('ol.proj.Units');
//goog.require('ol.tilegrid.TileGrid');

#include <ol/typedefs.h>
#include <ol/tilegrid/TileGrid.h>
#include <ol/extent/Corner.h>

namespace ol {
namespace tilegrid {

//
//
///**
// * @param {ol.proj.Projection} projection Projection.
// * @return {!ol.tilegrid.TileGrid} Default tile grid for the passed projection.
// */
//ol.tilegrid.getForProjection = function(projection) {
//  var tileGrid = projection.getDefaultTileGrid();
//  if (!tileGrid) {
//    tileGrid = ol.tilegrid.createForProjection(projection);
//    projection.setDefaultTileGrid(tileGrid);
//  }
//  return tileGrid;
//};
//
//
///**
// * @param {ol.tilegrid.TileGrid} tileGrid Tile grid.
// * @param {ol.TileCoord} tileCoord Tile coordinate.
// * @param {ol.proj.Projection} projection Projection.
// * @return {ol.TileCoord} Tile coordinate.
// */
//ol.tilegrid.wrapX = function(tileGrid, tileCoord, projection) {
//  var z = tileCoord[0];
//  var center = tileGrid.getTileCoordCenter(tileCoord);
//  var projectionExtent = ol.tilegrid.extentFromProjection(projection);
//  if (!ol.extent.containsCoordinate(projectionExtent, center)) {
//    var worldWidth = ol.extent.getWidth(projectionExtent);
//    var worldsAway = Math.ceil((projectionExtent[0] - center[0]) / worldWidth);
//    center[0] += worldWidth * worldsAway;
//    return tileGrid.getTileCoordForCoordAndZ(center, z);
//  } else {
//    return tileCoord;
//  }
//};
//
//
/**
 * @param {ol.Extent} extent Extent.
 * @param {number=} opt_maxZoom Maximum zoom level (default is
 *     ol.DEFAULT_MAX_ZOOM).
 * @param {number|ol.Size=} opt_tileSize Tile size (default uses
 *     ol.DEFAULT_TILE_SIZE).
 * @param {ol.extent.Corner=} opt_corner Extent corner (default is
 *     ol.extent.Corner.TOP_LEFT).
 * @return {!ol.tilegrid.TileGrid} TileGrid instance.
 */

ol::tilegrid::TileGrid OLQT_EXPORT createForExtent(ol::Extent const &extent, 
    int opt_maxZoom = ol::DEFAULT_MAX_ZOOM, ol::Size const &opt_tileSize = ol::Size(), 
    ol::extent::Corner::enum_t opt_corner = extent::Corner::TOP_LEFT);

//
//
///**
// * Creates a tile grid with a standard XYZ tiling scheme.
// * @param {olx.tilegrid.XYZOptions=} opt_options Tile grid options.
// * @return {!ol.tilegrid.TileGrid} Tile grid instance.
// * @api
// */
//ol.tilegrid.createXYZ = function(opt_options) {
//  var options = /** @type {olx.tilegrid.TileGridOptions} */ ({});
//  ol.obj.assign(options, opt_options !== undefined ?
//    opt_options : /** @type {olx.tilegrid.XYZOptions} */ ({}));
//  if (options.extent === undefined) {
//    options.extent = ol.proj.get('EPSG:3857').getExtent();
//  }
//  options.resolutions = ol.tilegrid.resolutionsFromExtent(
//      options.extent, options.maxZoom, options.tileSize);
//  delete options.maxZoom;
//
//  return new ol.tilegrid.TileGrid(options);
//};


/**
 * Create a resolutions array from an extent.  A zoom factor of 2 is assumed.
 * @param {ol.Extent} extent Extent.
 * @param {number=} opt_maxZoom Maximum zoom level (default is
 *     ol.DEFAULT_MAX_ZOOM).
 * @param {number|ol.Size=} opt_tileSize Tile size (default uses
 *     ol.DEFAULT_TILE_SIZE).
 * @return {!Array.<number>} Resolutions array.
 */

ol::resolutions_t OLQT_EXPORT resolutionsFromExtent (ol::Extent const &extent, int opt_maxZoom = ol::DEFAULT_MAX_ZOOM, 
    ol::Size const &opt_tileSize = ol::Size());;

//
//
///**
// * @param {ol.ProjectionLike} projection Projection.
// * @param {number=} opt_maxZoom Maximum zoom level (default is
// *     ol.DEFAULT_MAX_ZOOM).
// * @param {number|ol.Size=} opt_tileSize Tile size (default uses
// *     ol.DEFAULT_TILE_SIZE).
// * @param {ol.extent.Corner=} opt_corner Extent corner (default is
// *     ol.extent.Corner.BOTTOM_LEFT).
// * @return {!ol.tilegrid.TileGrid} TileGrid instance.
// */
//ol.tilegrid.createForProjection = function(projection, opt_maxZoom, opt_tileSize, opt_corner) {
//  var extent = ol.tilegrid.extentFromProjection(projection);
//  return ol.tilegrid.createForExtent(
//      extent, opt_maxZoom, opt_tileSize, opt_corner);
//};
//
//
///**
// * Generate a tile grid extent from a projection.  If the projection has an
// * extent, it is used.  If not, a global extent is assumed.
// * @param {ol.ProjectionLike} projection Projection.
// * @return {ol.Extent} Extent.
// */
//ol.tilegrid.extentFromProjection = function(projection) {
//  projection = ol.proj.get(projection);
//  var extent = projection.getExtent();
//  if (!extent) {
//    var half = 180 * ol.proj.METERS_PER_UNIT[ol.proj.Units.DEGREES] /
//        projection.getMetersPerUnit();
//    extent = ol.extent.createOrUpdate(-half, -half, half, half);
//  }
//  return extent;
//};
}
}

#endif // TILEGRID_H
