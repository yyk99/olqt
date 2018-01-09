//
// Based on Tag: v4.6.4
//

#ifndef OL_TILEGRID_TILEGRID_H
#define OL_TILEGRID_TILEGRID_H

//goog.provide('ol.tilegrid.TileGrid');
//
//goog.require('ol');
//goog.require('ol.asserts');
//goog.require('ol.TileRange');
//goog.require('ol.array');
//goog.require('ol.extent');
//goog.require('ol.math');
//goog.require('ol.size');
//goog.require('ol.tilecoord');

#include <ol/exports.h>
#include <ol/extent.h>
#include <ol/TileRange.h>

#include <vector>

namespace ol {

/// Resolutions. The array index of each resolution needs to match the zoom level. 
typedef std::vector<int> resolutions_t;

namespace tilegrid {

class OLQT_EXPORT TileGrid {
private:
    int minZoom;
    int maxZoom;
    ol::optional<ol::Extent> extent_;
    ol::resolutions_t resolutions_;
    ol::optional<double> zoomFactor_;
    ol::optional<ol::Coordinate> origin_;
    std::vector<ol::Coordinate> origins_;
    ol::optional<ol::Size> tileSize_;
    ol::optional<std::vector<ol::Size> > tileSizes_;

    std::vector<ol::TileRange> fullTileRanges_;
    ol::Size tmpSize_;
public:
    struct TileGridOptions {
        ol::optional<ol::Extent> extent;
        ol::optional<int> minZoom;
        ol::optional<ol::Coordinate> origin;
        std::vector<ol::Coordinate> origins;
        ol::optional<ol::Size> tileSize;
        ol::optional<std::vector<ol::Size> > tileSizes;
        std::vector<ol::Size> sizes;
    };

    ///**
    // * @classdesc
    // * Base class for setting the grid pattern for sources accessing tiled-image
    // * servers.
    // *
    // * @constructor
    // * @param {olx.tilegrid.TileGridOptions} options Tile grid options.
    // * @struct
    // * @api
    // */
    TileGrid(ol::resolutions_t resolutions, TileGridOptions const &options);
    //
    //
    ///**
    // * @private
    // * @type {ol.TileCoord}
    // */
    //ol.tilegrid.TileGrid.tmpTileCoord_ = [0, 0, 0];
	static ol::TileCoord tmpTileCoord_;
    //
    //
    ///**
    // * Call a function with each tile coordinate for a given extent and zoom level.
    // *
    // * @param {ol.Extent} extent Extent.
    // * @param {number} zoom Integer zoom level.
    // * @param {function(ol.TileCoord)} callback Function called with each tile coordinate.
    // * @api
    // */
    //ol.tilegrid.TileGrid.prototype.forEachTileCoord = function(extent, zoom, callback) {
    //  var tileRange = this.getTileRangeForExtentAndZ(extent, zoom);
    //  for (var i = tileRange.minX, ii = tileRange.maxX; i <= ii; ++i) {
    //    for (var j = tileRange.minY, jj = tileRange.maxY; j <= jj; ++j) {
    //      callback([zoom, i, j]);
    //    }
    //  }
    //};
    //
    //
    ///**
    // * @param {ol.TileCoord} tileCoord Tile coordinate.
    // * @param {function(this: T, number, ol.TileRange): boolean} callback Callback.
    // * @param {T=} opt_this The object to use as `this` in `callback`.
    // * @param {ol.TileRange=} opt_tileRange Temporary ol.TileRange object.
    // * @param {ol.Extent=} opt_extent Temporary ol.Extent object.
    // * @return {boolean} Callback succeeded.
    // * @template T
    // */
    //ol.tilegrid.TileGrid.prototype.forEachTileCoordParentTileRange = function(tileCoord, callback, opt_this, opt_tileRange, opt_extent) {
    //  var tileRange, x, y;
    //  var tileCoordExtent = null;
    //  var z = tileCoord[0] - 1;
    //  if (this.zoomFactor_ === 2) {
    //    x = tileCoord[1];
    //    y = tileCoord[2];
    //  } else {
    //    tileCoordExtent = this.getTileCoordExtent(tileCoord, opt_extent);
    //  }
    //  while (z >= this.minZoom) {
    //    if (this.zoomFactor_ === 2) {
    //      x = Math.floor(x / 2);
    //      y = Math.floor(y / 2);
    //      tileRange = ol.TileRange.createOrUpdate(x, x, y, y, opt_tileRange);
    //    } else {
    //      tileRange = this.getTileRangeForExtentAndZ(tileCoordExtent, z, opt_tileRange);
    //    }
    //    if (callback.call(opt_this, z, tileRange)) {
    //      return true;
    //    }
    //    --z;
    //  }
    //  return false;
    //};
    //
    //
    ///**
    // * Get the extent for this tile grid, if it was configured.
    // * @return {ol.Extent} Extent.
    // */
    ol::optional<ol::Extent> getExtent() const;
    //
    //
    ///**
    // * Get the maximum zoom level for the grid.
    // * @return {number} Max zoom.
    // * @api
    // */
    //ol.tilegrid.TileGrid.prototype.getMaxZoom = function() {
    //  return this.maxZoom;
    //};
    //
    //
    ///**
    // * Get the minimum zoom level for the grid.
    // * @return {number} Min zoom.
    // * @api
    // */
    //ol.tilegrid.TileGrid.prototype.getMinZoom = function() {
    //  return this.minZoom;
    //};
    //
    //
    ///**
    // * Get the origin for the grid at the given zoom level.
    // * @param {number} z Integer zoom level.
    // * @return {ol.Coordinate} Origin.
    // * @api
    // */
    ol::Coordinate const &getOrigin(int z = 0) const {
        //ol.tilegrid.TileGrid.prototype.getOrigin = function(z) {
          if (origin_.has_value()) {
              return origin_.value();
          } 
          return origins_[z];
    }
    //
    //
    ///**
    // * Get the resolution for the given zoom level.
    // * @param {number} z Integer zoom level.
    // * @return {number} Resolution.
    // * @api
    // */
    int getResolution(int z) const;
    //
    //
    ///**
    // * Get the list of resolutions for the tile grid.
    // * @return {Array.<number>} Resolutions.
    // * @api
    // */
    //ol.tilegrid.TileGrid.prototype.getResolutions = function() {
    //  return this.resolutions_;
    //};
    //
    //
    ///**
    // * @param {ol.TileCoord} tileCoord Tile coordinate.
    // * @param {ol.TileRange=} opt_tileRange Temporary ol.TileRange object.
    // * @param {ol.Extent=} opt_extent Temporary ol.Extent object.
    // * @return {ol.TileRange} Tile range.
    // */
    //ol.tilegrid.TileGrid.prototype.getTileCoordChildTileRange = function(tileCoord, opt_tileRange, opt_extent) {
    //  if (tileCoord[0] < this.maxZoom) {
    //    if (this.zoomFactor_ === 2) {
    //      var minX = tileCoord[1] * 2;
    //      var minY = tileCoord[2] * 2;
    //      return ol.TileRange.createOrUpdate(minX, minX + 1, minY, minY + 1, opt_tileRange);
    //    }
    //    var tileCoordExtent = this.getTileCoordExtent(tileCoord, opt_extent);
    //    return this.getTileRangeForExtentAndZ(
    //        tileCoordExtent, tileCoord[0] + 1, opt_tileRange);
    //  }
    //  return null;
    //};
    //
    //
    ///**
    // * Get the extent for a tile range.
    // * @param {number} z Integer zoom level.
    // * @param {ol.TileRange} tileRange Tile range.
    // * @param {ol.Extent=} opt_extent Temporary ol.Extent object.
    // * @return {ol.Extent} Extent.
    // */
    //ol.tilegrid.TileGrid.prototype.getTileRangeExtent = function(z, tileRange, opt_extent) {
    //  var origin = this.getOrigin(z);
    //  var resolution = this.getResolution(z);
    //  var tileSize = ol.size.toSize(this.getTileSize(z), this.tmpSize_);
    //  var minX = origin[0] + tileRange.minX * tileSize[0] * resolution;
    //  var maxX = origin[0] + (tileRange.maxX + 1) * tileSize[0] * resolution;
    //  var minY = origin[1] + tileRange.minY * tileSize[1] * resolution;
    //  var maxY = origin[1] + (tileRange.maxY + 1) * tileSize[1] * resolution;
    //  return ol.extent.createOrUpdate(minX, minY, maxX, maxY, opt_extent);
    //};
    //
    //
    ///**
    // * Get a tile range for the given extent and integer zoom level.
    // * @param {ol.Extent} extent Extent.
    // * @param {number} z Integer zoom level.
    // * @param {ol.TileRange=} opt_tileRange Temporary tile range object.
    // * @return {ol.TileRange} Tile range.
    // */
	ol::TileRange getTileRangeForExtentAndZ(ol::Extent extent, int z/*, ol::optional<ol::TileRange> opt_tileRange = ol::optional<ol::TileRange>()*/);
    //
    //
    ///**
    // * @param {ol.TileCoord} tileCoord Tile coordinate.
    // * @return {ol.Coordinate} Tile center.
    // */
    //ol.tilegrid.TileGrid.prototype.getTileCoordCenter = function(tileCoord) {
    //  var origin = this.getOrigin(tileCoord[0]);
    //  var resolution = this.getResolution(tileCoord[0]);
    //  var tileSize = ol.size.toSize(this.getTileSize(tileCoord[0]), this.tmpSize_);
    //  return [
    //    origin[0] + (tileCoord[1] + 0.5) * tileSize[0] * resolution,
    //    origin[1] + (tileCoord[2] + 0.5) * tileSize[1] * resolution
    //  ];
    //};
    //
    //
    ///**
    // * Get the extent of a tile coordinate.
    // *
    // * @param {ol.TileCoord} tileCoord Tile coordinate.
    // * @param {ol.Extent=} opt_extent Temporary extent object.
    // * @return {ol.Extent} Extent.
    // * @api
    // */
    //ol.tilegrid.TileGrid.prototype.getTileCoordExtent = function(tileCoord, opt_extent) {
    //  var origin = this.getOrigin(tileCoord[0]);
    //  var resolution = this.getResolution(tileCoord[0]);
    //  var tileSize = ol.size.toSize(this.getTileSize(tileCoord[0]), this.tmpSize_);
    //  var minX = origin[0] + tileCoord[1] * tileSize[0] * resolution;
    //  var minY = origin[1] + tileCoord[2] * tileSize[1] * resolution;
    //  var maxX = minX + tileSize[0] * resolution;
    //  var maxY = minY + tileSize[1] * resolution;
    //  return ol.extent.createOrUpdate(minX, minY, maxX, maxY, opt_extent);
    //};
    //
    //
    ///**
    // * Get the tile coordinate for the given map coordinate and resolution.  This
    // * method considers that coordinates that intersect tile boundaries should be
    // * assigned the higher tile coordinate.
    // *
    // * @param {ol.Coordinate} coordinate Coordinate.
    // * @param {number} resolution Resolution.
    // * @param {ol.TileCoord=} opt_tileCoord Destination ol.TileCoord object.
    // * @return {ol.TileCoord} Tile coordinate.
    // * @api
    // */
    //ol.tilegrid.TileGrid.prototype.getTileCoordForCoordAndResolution = function(coordinate, resolution, opt_tileCoord) {
    //  return this.getTileCoordForXYAndResolution_(
    //      coordinate[0], coordinate[1], resolution, false, opt_tileCoord);
    //};
    //
    //
    ///**
    // * Note that this method should not be called for resolutions that correspond
    // * to an integer zoom level.  Instead call the `getTileCoordForXYAndZ_` method.
    // * @param {number} x X.
    // * @param {number} y Y.
    // * @param {number} resolution Resolution (for a non-integer zoom level).
    // * @param {boolean} reverseIntersectionPolicy Instead of letting edge
    // *     intersections go to the higher tile coordinate, let edge intersections
    // *     go to the lower tile coordinate.
    // * @param {ol.TileCoord=} opt_tileCoord Temporary ol.TileCoord object.
    // * @return {ol.TileCoord} Tile coordinate.
    // * @private
    // */
    //ol.tilegrid.TileGrid.prototype.getTileCoordForXYAndResolution_ = function(
    //    x, y, resolution, reverseIntersectionPolicy, opt_tileCoord) {
    //  var z = this.getZForResolution(resolution);
    //  var scale = resolution / this.getResolution(z);
    //  var origin = this.getOrigin(z);
    //  var tileSize = ol.size.toSize(this.getTileSize(z), this.tmpSize_);
    //
    //  var adjustX = reverseIntersectionPolicy ? 0.5 : 0;
    //  var adjustY = reverseIntersectionPolicy ? 0 : 0.5;
    //  var xFromOrigin = Math.floor((x - origin[0]) / resolution + adjustX);
    //  var yFromOrigin = Math.floor((y - origin[1]) / resolution + adjustY);
    //  var tileCoordX = scale * xFromOrigin / tileSize[0];
    //  var tileCoordY = scale * yFromOrigin / tileSize[1];
    //
    //  if (reverseIntersectionPolicy) {
    //    tileCoordX = Math.ceil(tileCoordX) - 1;
    //    tileCoordY = Math.ceil(tileCoordY) - 1;
    //  } else {
    //    tileCoordX = Math.floor(tileCoordX);
    //    tileCoordY = Math.floor(tileCoordY);
    //  }
    //
    //  return ol.tilecoord.createOrUpdate(z, tileCoordX, tileCoordY, opt_tileCoord);
    //};
    //
    //
	///**
	// * Although there is repetition between this method and `getTileCoordForXYAndResolution_`,
	// * they should have separate implementations.  This method is for integer zoom
	// * levels.  The other method should only be called for resolutions corresponding
	// * to non-integer zoom levels.
	// * @param {number} x Map x coordinate.
	// * @param {number} y Map y coordinate.
	// * @param {number} z Integer zoom level.
	// * @param {boolean} reverseIntersectionPolicy Instead of letting edge
	// *     intersections go to the higher tile coordinate, let edge intersections
	// *     go to the lower tile coordinate.
	// * @param {ol.TileCoord=} opt_tileCoord Temporary ol.TileCoord object.
	// * @return {ol.TileCoord} Tile coordinate.
	// * @private
	// */
	ol::TileCoord getTileCoordForXYAndZ_(int x, int y, int z, bool reverseIntersectionPolicy, ol::optional<ol::TileCoord> opt_tileCoord = ol::optional<ol::TileCoord>());
    //
    //
    ///**
    // * Get a tile coordinate given a map coordinate and zoom level.
    // * @param {ol.Coordinate} coordinate Coordinate.
    // * @param {number} z Zoom level.
    // * @param {ol.TileCoord=} opt_tileCoord Destination ol.TileCoord object.
    // * @return {ol.TileCoord} Tile coordinate.
    // * @api
    // */
    //ol.tilegrid.TileGrid.prototype.getTileCoordForCoordAndZ = function(coordinate, z, opt_tileCoord) {
    //  return this.getTileCoordForXYAndZ_(
    //      coordinate[0], coordinate[1], z, false, opt_tileCoord);
    //};
    //
    //
    ///**
    // * @param {ol.TileCoord} tileCoord Tile coordinate.
    // * @return {number} Tile resolution.
    // */
    //ol.tilegrid.TileGrid.prototype.getTileCoordResolution = function(tileCoord) {
    //  return this.resolutions_[tileCoord[0]];
    //};
    //
    //
    ///**
    // * Get the tile size for a zoom level. The type of the return value matches the
    // * `tileSize` or `tileSizes` that the tile grid was configured with. To always
    // * get an `ol.Size`, run the result through `ol.size.toSize()`.
    // * @param {number} z Z.
    // * @return {number|ol.Size} Tile size.
    // * @api
    // */
    //ol.tilegrid.TileGrid.prototype.getTileSize = function(z) {
    //  if (this.tileSize_) {
    //    return this.tileSize_;
    //  } else {
    //    return this.tileSizes_[z];
    //  }
    //};
    //
    //
    ///**
    // * @param {number} z Zoom level.
    // * @return {ol.TileRange} Extent tile range for the specified zoom level.
    // */
    ol::optional<ol::TileRange> getFullTileRange(int z);
    //
    //
    ///**
    // * @param {number} resolution Resolution.
    // * @param {number=} opt_direction If 0, the nearest resolution will be used.
    // *     If 1, the nearest lower resolution will be used. If -1, the nearest
    // *     higher resolution will be used. Default is 0.
    // * @return {number} Z.
    // * @api
    // */
    //ol.tilegrid.TileGrid.prototype.getZForResolution = function(
    //    resolution, opt_direction) {
    //  var z = ol.array.linearFindNearest(this.resolutions_, resolution,
    //      opt_direction || 0);
    //  return ol.math.clamp(z, this.minZoom, this.maxZoom);
    //};
    //
    //
    ///**
    // * @param {!ol.Extent} extent Extent for this tile grid.
    // * @private
    // */
    void calculateTileRanges_(ol::Extent const &extent);
};

}
}

#endif
