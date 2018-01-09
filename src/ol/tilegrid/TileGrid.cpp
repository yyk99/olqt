//
//
//

#include "TileGrid.h"

#include <algorithm>
#include <functional>

template <class ForwardIterator>
bool is_desc_sorted(ForwardIterator first, ForwardIterator last)
{
    if (first == last)
        return true;
    ForwardIterator next = first;
    while (++next != last) {
        if (*next >= *first)     // or, if (comp(*next,*first)) for version (2)
            return false;
        ++first;
    }
    return true;
}

ol::tilegrid::TileGrid::TileGrid(ol::resolutions_t resolutions, TileGridOptions const &options) :
    resolutions_(resolutions)
{
    //ol.tilegrid.TileGrid = function(options) {
    //
    //  /**
    //   * @protected
    //   * @type {number}
    //   */
    minZoom = options.minZoom.has_value() ? options.minZoom.value() : 0;
    //
    //  /**
    //   * @private
    //   * @type {!Array.<number>}
    //   */
    //  this.resolutions_ = options.resolutions;
    //  ol.asserts.assert(ol.array.isSorted(this.resolutions_, function(a, b) {
    //    return b - a;
    //  }, true), 17); // `resolutions` must be sorted in descending order
    if (!is_desc_sorted(resolutions_.begin(), resolutions_.end()))
        throw std::runtime_error("17 - `resolutions` must be sorted in descending order");

    //
    //
    //  // check if we've got a consistent zoom factor and origin
    optional<double> zoomFactor;
    if (options.origins.size() == 0) {
        for (size_t i = 0, ii = resolutions_.size() - 1; i < ii; ++i) {
            if (!zoomFactor.has_value()) {
                zoomFactor = resolutions_[i] / resolutions_[i + 1];
            } else {
                if (resolutions_[i] / resolutions_[i + 1] != zoomFactor.value()) {
                    zoomFactor.reset();
                    break;
                }
            }
        }
    }
    /**
     * @private
     * @type {number|undefined}
     */
    zoomFactor_ = zoomFactor;

    /**
     * @protected
     * @type {number}
     */
    maxZoom = int(resolutions_.size() - 1);

    /**
     * @private
     * @type {ol.Coordinate}
     */
    origin_ = options.origin;

    /**
     * @private
     * @type {Array.<ol.Coordinate>}
     */
    origins_.clear();
    if (options.origins.size()) {
        origins_ = options.origins;
        //ol.asserts.assert(this.origins_.length == this.resolutions_.length,
        //    20); // Number of `origins` and `resolutions` must be equal
        if (origins_.size() != resolutions_.size())
            throw std::runtime_error("20 - Number of `origins` and `resolutions` must be equal");
    }

    auto extent = options.extent;
    if (extent.has_value() && !origin_.has_value() && origins_.size() == 0) {
        origin_ = ol::extent::getTopLeft(extent.value());
    }

    //ol.asserts.assert(
    //    (!this.origin_ && this.origins_) || (this.origin_ && !this.origins_),
    //    18); // Either `origin` or `origins` must be configured, never both
    if (origin_.has_value() == (origins_.size() != 0))
        throw std::runtime_error("18 - Either `origin` or `origins` must be configured, never both");

    /**
     * @private
     * @type {Array.<number|ol.Size>}
     */
    tileSizes_.reset();
    if (options.tileSizes.has_value()) {
        tileSizes_ = options.tileSizes;
        if (tileSizes_.value().size() != resolutions_.size())
            throw std::runtime_error("19 - Number of `tileSizes` and `resolutions` must be equal");
    }

    /**
     * @private
     * @type {number|ol.Size}
     */
    tileSize_ = options.tileSize.has_value() ?
        options.tileSize :
        !tileSizes_.has_value() ? ol::Size(2, ol::DEFAULT_TILE_SIZE) : ol::optional<ol::Size>();
    if (tileSize_.has_value() == tileSizes_.has_value())
        throw std::runtime_error("22 - Either `tileSize` or `tileSizes` must be configured, never both");

    /**
     * @private
     * @type {ol.Extent}
     */
    extent_ = extent;

    /**
     * @private
     * @type {Array.<ol.TileRange>}
     */
     //this.fullTileRanges_ = null;

     /**
      * @private
      * @type {ol.Size}
      */
      //this.tmpSize_ = [0, 0];

      if (options.sizes.size() != 0) {
          throw std::runtime_error("Not implemented");
          //this.fullTileRanges_ = options.sizes.map(function(size, z) {
          //    var tileRange = new ol.TileRange(
          //        Math.min(0, size[0]), Math.max(size[0] - 1, -1),
          //        Math.min(0, size[1]), Math.max(size[1] - 1, -1));
          //    return tileRange;
          //}, this);
      } else if (extent.has_value()) {
          calculateTileRanges_(extent.value());
      }
}

ol::TileCoord ol::tilegrid::TileGrid::tmpTileCoord_; // = [0,0,0]

ol::optional<ol::Extent> ol::tilegrid::TileGrid::getExtent() const
{
    //ol.tilegrid.TileGrid.prototype.getExtent = function() {
    //  return this.extent_;
    //};
    return extent_;
}

int ol::tilegrid::TileGrid::getResolution(int z) const
{
	return resolutions_[z];
}

//ol.tilegrid.TileGrid.prototype.getTileRangeForExtentAndZ = function(extent, z, opt_tileRange) {
ol::TileRange ol::tilegrid::TileGrid::getTileRangeForExtentAndZ(ol::Extent extent, int z)
{
	  auto tileCoord = ol::tilegrid::TileGrid::tmpTileCoord_;
	  getTileCoordForXYAndZ_(extent[0], extent[1], z, false, tileCoord);
	  int minX = std::get<1>(tileCoord); // [1];
	  int minY = std::get<2>(tileCoord); // [2];
	  getTileCoordForXYAndZ_(extent[2], extent[3], z, true, tileCoord);
	  return ol::TileRange::createOrUpdate(minX, std::get<1>(tileCoord), minY, std::get<2>(tileCoord));
}

ol::TileCoord ol::tilegrid::TileGrid::getTileCoordForXYAndZ_(int x, int y, int z, bool reverseIntersectionPolicy, ol::optional<ol::TileCoord> opt_tileCoord /*= ol::optional<ol::TileCoord>()*/)
{
	throw std::runtime_error("Not implemented");

	////ol.tilegrid.TileGrid.prototype.getTileCoordForXYAndZ_ = function(x, y, z, reverseIntersectionPolicy, opt_tileCoord) {
	//  auto origin = getOrigin(z);
	//  auto resolution = getResolution(z);
	//  var tileSize = ol.size.toSize(this.getTileSize(z), this.tmpSize_);
	//
	//  var adjustX = reverseIntersectionPolicy ? 0.5 : 0;
	//  var adjustY = reverseIntersectionPolicy ? 0 : 0.5;
	//  var xFromOrigin = Math.floor((x - origin[0]) / resolution + adjustX);
	//  var yFromOrigin = Math.floor((y - origin[1]) / resolution + adjustY);
	//  var tileCoordX = xFromOrigin / tileSize[0];
	//  var tileCoordY = yFromOrigin / tileSize[1];
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
}

ol::optional<ol::TileRange> ol::tilegrid::TileGrid::getFullTileRange(int z)
{
    if (fullTileRanges_.size() == 0) {
        return ol::optional<ol::TileRange>();
    }
    return ol::optional<ol::TileRange>(fullTileRanges_[z]);
}

void ol::tilegrid::TileGrid::calculateTileRanges_(ol::Extent const &extent)
{
    throw std::runtime_error("Not implemented");
    //ol.tilegrid.TileGrid.prototype.calculateTileRanges_ = function(extent) {
      size_t length = resolutions_.size();
      std::vector<ol::TileRange> fullTileRanges(length);
	  for (int z = minZoom; z != length; ++z) {
		  fullTileRanges[z] = getTileRangeForExtentAndZ(extent, z);
	  }
      fullTileRanges_ = fullTileRanges;
}
