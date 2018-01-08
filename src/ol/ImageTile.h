//
//
//

#ifndef OL_IMAGETILE_H
#define OL_IMAGETILE_H

#include <ol/Tile.h>

namespace ol {

class ImageElement; // FORWARD

//ol.TileLoadFunctionType() src / ol / typedefs.js, line 711
//A function that takes an ol.Tile for the tile and a{ string } for the url as arguments.

class OLQT_EXPORT TileLoadFunctionType {
public:
	virtual void operator () (ol::Tile *tile, std::string const &url) = 0;
};

//goog.provide('ol.ImageTile');
//
//goog.require('ol');
//goog.require('ol.Tile');
//goog.require('ol.TileState');
//goog.require('ol.dom');
//goog.require('ol.events');
//goog.require('ol.events.EventType');
//
//
class OLQT_EXPORT ImageTile : public ol::Tile {
	/**
	 * @constructor
	 * @extends {ol.Tile}
	 * @param {ol.TileCoord} tileCoord Tile coordinate.
	 * @param {ol.TileState} state State.
	 * @param {string} src Image source URI.
	 * @param {?string} crossOrigin Cross origin.
	 * @param {ol.TileLoadFunctionType} tileLoadFunction Tile load function.
	 * @param {olx.TileOptions=} opt_options Tile options.
	 */
public:
	struct Options {

	};

	ImageTile(ol::TileCoord tileCoord, ol::TileState::enum_t state, std::string src, 
		std::string crossOrigin, ol::TileLoadFunctionType &tileLoadFunction, Options *opt_options = 0)
		: ol::Tile(tileCoord, state), src_(src)
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
	};

	/**
	 * @inheritDoc
	 */
	virtual void disposeInternal() override 
	{
		//ol.ImageTile.prototype.disposeInternal = function() {
		//  if (this.state == ol.TileState.LOADING) {
		//    this.unlistenImage_();
		//    this.image_ = ol.ImageTile.getBlankImage();
		//  }
		//  if (this.interimTile) {
		//    this.interimTile.dispose();
		//  }
		//  this.state = ol.TileState.ABORT;
		//  this.changed();
		//  ol.Tile.prototype.disposeInternal.call(this);
		//};
	}


	/**
	 * Get the HTML image element for this tile (may be a Canvas, Image, or Video).
	 * @return {HTMLCanvasElement|HTMLImageElement|HTMLVideoElement} Image.
	 * @api
	 */
	virtual ol::ImageElement *getImage() {
		//ol.ImageTile.prototype.getImage = function() {
		//  return this.image_;
		//};
		return 0; // TODO: implement
	}


	/**
	 * @inheritDoc
	 */
	virtual std::string getKey() override
	{
		//ol.ImageTile.prototype.getKey = function() {
		//  return this.src_;
		//};
		return src_;
	}


	/**
	 * Tracks loading or read errors.
	 *
	 * @private
	 */
private:
	void handleImageError_() {
		//ol.ImageTile.prototype.handleImageError_ = function() {
		//  this.state = ol.TileState.ERROR;
		//  this.unlistenImage_();
		//  this.image_ = ol.ImageTile.getBlankImage();
		//  this.changed();
		//};
	}


	/**
	 * Tracks successful image load.
	 *
	 * @private
	 */
	void handleImageLoad_()
	{
		//ol.ImageTile.prototype.handleImageLoad_ = function() {
		//  if (this.image_.naturalWidth && this.image_.naturalHeight) {
		//    this.state = ol.TileState.LOADED;
		//  } else {
		//    this.state = ol.TileState.EMPTY;
		//  }
		//  this.unlistenImage_();
		//  this.changed();
		//};
	}
public:
	
	/**
	 * @inheritDoc
	 * @api
	 */
	void load() override
	{
		//ol.ImageTile.prototype.load = function() {
		//  if (this.state == ol.TileState.ERROR) {
		//    this.state = ol.TileState.IDLE;
		//    this.image_ = new Image();
		//    if (this.crossOrigin_ !== null) {
		//      this.image_.crossOrigin = this.crossOrigin_;
		//    }
		//  }
		//  if (this.state == ol.TileState.IDLE) {
		//    this.state = ol.TileState.LOADING;
		//    this.changed();
		//    this.imageListenerKeys_ = [
		//      ol.events.listenOnce(this.image_, ol.events.EventType.ERROR,
		//          this.handleImageError_, this),
		//      ol.events.listenOnce(this.image_, ol.events.EventType.LOAD,
		//          this.handleImageLoad_, this)
		//    ];
		//    this.tileLoadFunction_(this, this.src_);
		//  }
		//};
	}


	/**
	 * Discards event handlers which listen for load completion or errors.
	 *
	 * @private
	 */
private:
	void unlistenImage_()
	{
		//ol.ImageTile.prototype.unlistenImage_ = function() {
		//  this.imageListenerKeys_.forEach(ol.events.unlistenByKey);
		//  this.imageListenerKeys_ = null;
		//};
	}

	/**
	 * Get a 1-pixel blank image.
	 * @return {HTMLCanvasElement} Blank image.
	 */
	virtual ol::ImageElement *getBlankImage() const
	{
		//ol.ImageTile.getBlankImage = function() {
		//  var ctx = ol.dom.createCanvasContext2D(1, 1);
		//  ctx.fillStyle = 'rgba(0,0,0,0)';
		//  ctx.fillRect(0, 0, 1, 1);
		//  return ctx.canvas;
		//};
		return 0; // TODO: Implement
	}
private:
	std::string src_;
};

}

#endif
