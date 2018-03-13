//
// Copyright (c) 2018
// Use of this source code is governed by a license that
// can be found in the LICENSE file.
//

#ifndef OL_IMAGE_H
#define OL_IMAGE_H

#include <ol/imagebase.h>

namespace ol {

//goog.provide('ol.Image');
//
//goog.require('ol');
//goog.require('ol.ImageBase');
//goog.require('ol.ImageState');
//goog.require('ol.events');
//goog.require('ol.events.EventType');
//goog.require('ol.extent');
//
//
///**
// * @constructor
// * @extends {ol.ImageBase}
// * @param {ol.Extent} extent Extent.
// * @param {number|undefined} resolution Resolution.
// * @param {number} pixelRatio Pixel ratio.
// * @param {string} src Image source URI.
// * @param {?string} crossOrigin Cross origin.
// * @param {ol.ImageLoadFunctionType} imageLoadFunction Image load function.
// */

class Image : public ol::ImageBase {
private:
    std::string src_;
    Image *image_;
public:
    Image() 
        : ol::ImageBase(ol::Extent(), 0, 0, ol::ImageState::IDLE)
        , src_()
        , image_()
    {}

    Image (ol::Extent extent, ol::number_t resolution, ol::number_t pixelRatio, std::string src, std::string crossOrigin, void *imageLoadFunction) 
        : ol::ImageBase(extent, resolution, pixelRatio, ol::ImageState::IDLE)
        , src_(src)
        , image_(new Image())
    {
    //
    //  ol.ImageBase.call(this, extent, resolution, pixelRatio, ol.ImageState.IDLE);
    //
    //  /**
    //   * @private
    //   * @type {string}
    //   */
    //  this.src_ = src;
    //
    //  /**
    //   * @private
    //   * @type {HTMLCanvasElement|Image|HTMLVideoElement}
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
    //   * @protected
    //   * @type {ol.ImageState}
    //   */
    //  this.state = ol.ImageState.IDLE;
    //
    //  /**
    //   * @private
    //   * @type {ol.ImageLoadFunctionType}
    //   */
    //  this.imageLoadFunction_ = imageLoadFunction;
    //
    };
    //ol.inherits(ol.Image, ol.ImageBase);
    //
    //
    ///**
    // * @inheritDoc
    // * @api
    // */
    //ol.Image.prototype.getImage = function() {
    //  return this.image_;
    //};
    //
    //
    ///**
    // * Tracks loading or read errors.
    // *
    // * @private
    // */
    //ol.Image.prototype.handleImageError_ = function() {
    //  this.state = ol.ImageState.ERROR;
    //  this.unlistenImage_();
    //  this.changed();
    //};
    //
    //
    ///**
    // * Tracks successful image load.
    // *
    // * @private
    // */
    //ol.Image.prototype.handleImageLoad_ = function() {
    //  if (this.resolution === undefined) {
    //    this.resolution = ol.extent.getHeight(this.extent) / this.image_.height;
    //  }
    //  this.state = ol.ImageState.LOADED;
    //  this.unlistenImage_();
    //  this.changed();
    //};
    //
    //
    ///**
    // * Load the image or retry if loading previously failed.
    // * Loading is taken care of by the tile queue, and calling this method is
    // * only needed for preloading or for reloading in case of an error.
    // * @override
    // * @api
    // */
    //ol.Image.prototype.load = function() {
    //  if (this.state == ol.ImageState.IDLE || this.state == ol.ImageState.ERROR) {
    //    this.state = ol.ImageState.LOADING;
    //    this.changed();
    //    this.imageListenerKeys_ = [
    //      ol.events.listenOnce(this.image_, ol.events.EventType.ERROR,
    //          this.handleImageError_, this),
    //      ol.events.listenOnce(this.image_, ol.events.EventType.LOAD,
    //          this.handleImageLoad_, this)
    //    ];
    //    this.imageLoadFunction_(this, this.src_);
    //  }
    //};
    //
    //
    ///**
    // * @param {HTMLCanvasElement|Image|HTMLVideoElement} image Image.
    // */
    //ol.Image.prototype.setImage = function(image) {
    //  this.image_ = image;
    //};
    //
    //
    ///**
    // * Discards event handlers which listen for load completion or errors.
    // *
    // * @private
    // */
    //ol.Image.prototype.unlistenImage_ = function() {
    //  this.imageListenerKeys_.forEach(ol.events.unlistenByKey);
    //  this.imageListenerKeys_ = null;
    //};
    //

    virtual void * getImage() override;


    virtual void load() override;

protected:
    virtual void disposeInternal() override;

};
}

#endif
