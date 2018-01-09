//
//
//

#include "TileGrid.h"

#include <algorithm>
#include <functional>
#include <cmath>

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
        //this.fullTileRanges_ = options.sizes.map(function(size, z) {
        //    var tileRange = new ol.TileRange(
        //        Math.min(0, size[0]), Math.max(size[0] - 1, -1),
        //        Math.min(0, size[1]), Math.max(size[1] - 1, -1));
        //    return tileRange;
        //}, this);
        fullTileRanges_.resize(options.sizes.size());
        for (int z = 0; z != options.sizes.size(); ++z) {
            auto s = options.sizes[z];
            auto tileRange = ol::TileRange(
                std::min(0, s[0]), std::max(s[0] - 1, -1),
                std::min(0, s[1]), std::max(s[1] - 1, -1));
            fullTileRanges_[z] = tileRange;
        }
    } else if (extent.has_value()) {
        calculateTileRanges_(extent.value());
    }
}

ol::TileCoord ol::tilegrid::TileGrid::tmpTileCoord_; // = [0,0,0]

//ol.tilegrid.TileGrid.prototype.getExtent = function()
ol::optional<ol::Extent> ol::tilegrid::TileGrid::getExtent() const
{
    return extent_;
}

//ol.tilegrid.TileGrid.prototype.getOrigin = function(z) {
ol::Coordinate const & ol::tilegrid::TileGrid::getOrigin(int z /*= 0*/) const
{
    if (origin_.has_value()) {
        return origin_.value();
    }
    return origins_[z];
}

int ol::tilegrid::TileGrid::getResolution(int z) const
{
	return resolutions_[z];
}

//ol.tilegrid.TileGrid.prototype.getTileRangeForExtentAndZ = function(extent, z, opt_tileRange) {
ol::TileRange ol::tilegrid::TileGrid::getTileRangeForExtentAndZ(ol::Extent extent, int z)
{
    ol::TileCoord tileCoord = getTileCoordForXYAndZ_(extent[0], extent[1], z, false);
    int minX = std::get<1>(tileCoord); // [1];
    int minY = std::get<2>(tileCoord); // [2];
    tileCoord = getTileCoordForXYAndZ_(extent[2], extent[3], z, true);
    return ol::TileRange::createOrUpdate(minX, std::get<1>(tileCoord), minY, std::get<2>(tileCoord));
}

//ol.tilegrid.TileGrid.prototype.getTileCoordForXYAndZ_ = function(x, y, z, reverseIntersectionPolicy, opt_tileCoord) {
ol::TileCoord ol::tilegrid::TileGrid::getTileCoordForXYAndZ_(int x, int y, int z, bool reverseIntersectionPolicy)
{
    auto origin = getOrigin(z);
    auto resolution = getResolution(z);
    auto tileSize = getTileSize(z);

    double adjustX = reverseIntersectionPolicy ? 0.5 : 0;
    double adjustY = reverseIntersectionPolicy ? 0 : 0.5;
    double xFromOrigin = std::floor((x - origin[0]) / resolution + adjustX);
    double yFromOrigin = std::floor((y - origin[1]) / resolution + adjustY);
    double tileCoordX = xFromOrigin / tileSize[0];
    double tileCoordY = yFromOrigin / tileSize[1];

    if (reverseIntersectionPolicy) {
        tileCoordX = std::ceil(tileCoordX) - 1;
        tileCoordY = std::ceil(tileCoordY) - 1;
    } else {
        tileCoordX = std::floor(tileCoordX);
        tileCoordY = std::floor(tileCoordY);
    }

    return ol::TileCoord(z, int(tileCoordX), int(tileCoordY));
}

ol::Size const & ol::tilegrid::TileGrid::getTileSize(int z) const
{
    if (tileSize_.has_value()) {
        return tileSize_.value();
    }
    return tileSizes_.value()[z];
}

ol::optional<ol::TileRange> ol::tilegrid::TileGrid::getFullTileRange(int z)
{
    if (fullTileRanges_.size() == 0) {
        return ol::optional<ol::TileRange>();
    }
    return ol::optional<ol::TileRange>(fullTileRanges_[z]);
}

//ol.tilegrid.TileGrid.prototype.calculateTileRanges_ = function(extent) {
void ol::tilegrid::TileGrid::calculateTileRanges_(ol::Extent const &extent)
{
    size_t length = resolutions_.size();
    std::vector<ol::TileRange> fullTileRanges(length);
    for (int z = minZoom; z != length; ++z) {
        fullTileRanges[z] = getTileRangeForExtentAndZ(extent, z);
    }
    fullTileRanges_ = fullTileRanges;
}
