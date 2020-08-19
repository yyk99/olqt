//
//
//

#include <ol/ImageTile.h>


ol::ImageTile::ImageTile(ol::TileCoord const &tileCoord, ol::TileState::enum_t state, std::string const &src, std::string const &crossOrigin, ol::TileLoadFunctionType &tileLoadFunction, Options *opt_options /*= 0*/) 
    : ol::Tile(tileCoord, state), src_(src), image_(new ol::Image())
{
    //ol.ImageTile = function(tileCoord, state, src, crossOrigin, tileLoadFunction, opt_options) {
    //
    //  ol.Tile.call(this, tileCoord, state, opt_options);
    //
    //  /**
    //   * @private
    //   * @type {?string}
    //   */
    //  this.crossOrigin_ = crossOrigin;
    //
    //  /**
    //   * Image URI
    //   *
    //   * @private
    //   * @type {string}
    //   */
    //  this.src_ = src;
    //
    //  /**
    //   * @private
    //   * @type {Image|HTMLCanvasElement}
    //   */
    //  this.image_ = new Image();
    //  if (crossOrigin !== null) {
    //    this.image_.crossOrigin = crossOrigin;
    //  }
    //
    //  /**
    //   * @private
    //   * @type {Array.<ol.EventsKey>}
    //   */
    //  this.imageListenerKeys_ = null;
    //
    //  /**
    //   * @private
    //   * @type {ol.TileLoadFunctionType}
    //   */
    //  this.tileLoadFunction_ = tileLoadFunction;
    //
}

ol::ImageTile::~ImageTile()
{

}
