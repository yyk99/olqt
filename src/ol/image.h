//
// Copyright (c) 2018
// Use of this source code is governed by a license that
// can be found in the LICENSE file.
//

#ifndef OL_IMAGE_H
#define OL_IMAGE_H

#include <ol/imagebase.h>
#include <ol/events.h>

namespace ol {

class Image;
typedef void ImageLoadFunctionType(Image *, std::string const &);

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

class HTMLImageElement {
public:
    HTMLImageElement() {}
};

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
    ol::Image *image_;
    ol::ImageLoadFunctionType *imageLoadFunction_;
   std::vector<ol::EventsKey> imageListenerKeys_;

protected:
    std::string crossOrigin;

public:
    Image()
        : ol::ImageBase(ol::Extent(), ol::number_t(), ol::number_t(), ol::ImageState::IDLE)
        , src_()
        , image_()
    {}

    Image (ol::Extent extent, ol::number_t resolution, ol::number_t pixelRatio, std::string src, std::string xOrigin, ol::ImageLoadFunctionType *imageLoadFunction) 
        //  ol.ImageBase.call(this, extent, resolution, pixelRatio, ol.ImageState.IDLE);
        : ol::ImageBase(extent, resolution, pixelRatio, ol::ImageState::IDLE)
        , src_(src)
        , image_(new Image())
        , imageLoadFunction_(imageLoadFunction)
    {
    //
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
    state = ol::ImageState::IDLE;
    //
    //  /**
    //   * @private
    //   * @type {ol.ImageLoadFunctionType}
    //   */
    //  this.imageLoadFunction_ = imageLoadFunction;
    //
    };
    //ol.inherits(ol.Image, ol.ImageBase);
    
    ~Image() {
        dispose();
    }
    
    /**
     * @inheritDoc
     * @api
     */
    virtual ol::Image *getImage() const override {
        return image_;
    };
    
    
    /**
     * Tracks loading or read errors.
     *
     * @private
     */
    static void handleImageError_(void *obj, void *);;


    /**
     * Tracks successful image load.
     *
     * @private
     */
    static void handleImageLoad_(void *obj, void *);


    /**
     * Load the image or retry if loading previously failed.
     * Loading is taken care of by the tile queue, and calling this method is
     * only needed for preloading or for reloading in case of an error.
     * @override
     * @api
     */
    virtual void load() override;
    
    
    /**
     * @param {HTMLCanvasElement|Image|HTMLVideoElement} image Image.
     */
    void setImage (Image *image) {
        image_ = image;
    };
    
    
    /**
     * Discards event handlers which listen for load completion or errors.
     *
     * @private
     */
    void unlistenImage_ () {
        // TODO:
        //this.imageListenerKeys_.forEach(ol.events.unlistenByKey);
        //this.imageListenerKeys_ = null;
    };

protected:
    virtual void disposeInternal() override;

};
}

#endif
