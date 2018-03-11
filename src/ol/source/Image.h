//
// Copyright (c) 2018
// Use of this source code is governed by a license that
// can be found in the LICENSE file.
//

#ifndef OL_SOURCE_IMAGE_H
#define OL_SOURCE_IMAGE_H

// Based on https://github.com/openlayers/openlayers/blob/v4.6.4/src/ol/source/image.js

#include "Source.h"
#include <ol/imagebase.h>

//
//goog.provide('ol.source.Image');
//
//goog.require('ol');
//goog.require('ol.ImageState');
//goog.require('ol.array');
//goog.require('ol.events.Event');
//goog.require('ol.extent');
//goog.require('ol.proj');
//goog.require('ol.reproj.Image');
//goog.require('ol.source.Source');
//
//
///**
//* @classdesc
//* Abstract base class; normally only used for creating subclasses and not
//* instantiated in apps.
//* Base class for sources providing a single image.
//*
//* @constructor
//* @abstract
//* @extends {ol.source.Source}
//* @param {ol.SourceImageOptions} options Single image source options.
//* @api
//*/

#include <memory>

namespace ol {
namespace source {

class OLQT_EXPORT Image : public ol::source::Source {
private:
    ol::resolutions_t resolutions_;
    int reprojectedRevision_;
public:
    struct Image_options : public Source::Options {
    };

    Image(Image_options const &options) : ol::source::Source(options)
    {
//    ol.source.Source.call(this, {
//    attributions: options.attributions,
//    extent : options.extent,
//    logo : options.logo,
//    projection : options.projection,
//    state : options.state
//    });
//
//    /**
//    * @private
//    * @type {Array.<number>}
//    */
//    this.resolutions_ = options.resolutions != = undefined ?
//        options.resolutions : null;
//
//
//    /**
//    * @private
//    * @type {ol.reproj.Image}
//    */
//    this.reprojectedImage_ = null;
//
//
//    /**
//    * @private
//    * @type {number}
//    */
//    this.reprojectedRevision_ = 0;
        reprojectedRevision_ = 0;
    };
//ol.inherits(ol.source.Image, ol.source.Source);


    /**
    * @return {Array.<number>} Resolutions.
    * @override
    */
    virtual ol::resolutions_t getResolutions() {
        return resolutions_;
    }


    /**
    * @protected
    * @param {number} resolution Resolution.
    * @return {number} Resolution.
    */
    ol::number_t findNearestResolution(ol::number_t resolution);;


    /**
    * @param {ol.Extent} extent Extent.
    * @param {number} resolution Resolution.
    * @param {number} pixelRatio Pixel ratio.
    * @param {ol.proj.Projection} projection Projection.
    * @return {ol.ImageBase} Single image.
    */
    ol::ImageBase *getImage(ol::Extent extent, ol::number_t resolution, ol::number_t pixelRation, ol::proj::Projection projection)
    {
        //ol.source.Image.prototype.getImage = function(extent, resolution, pixelRatio, projection) {
        //    var sourceProjection = this.getProjection();
        //    if (!ol.ENABLE_RASTER_REPROJECTION ||
        //        !sourceProjection ||
        //        !projection ||
        //        ol.proj.equivalent(sourceProjection, projection)) {
        //        if (sourceProjection) {
        //            projection = sourceProjection;
        //        }
        //        return this.getImageInternal(extent, resolution, pixelRatio, projection);
        //    }
        //    else {
        //        if (this.reprojectedImage_) {
        //            if (this.reprojectedRevision_ == this.getRevision() &&
        //                ol.proj.equivalent(
        //                    this.reprojectedImage_.getProjection(), projection) &&
        //                this.reprojectedImage_.getResolution() == resolution &&
        //                ol.extent.equals(this.reprojectedImage_.getExtent(), extent)) {
        //                return this.reprojectedImage_;
        //            }
        //            this.reprojectedImage_.dispose();
        //            this.reprojectedImage_ = null;
        //        }
        //
        //        this.reprojectedImage_ = new ol.reproj.Image(
        //            sourceProjection, projection, extent, resolution, pixelRatio,
        //            function(extent, resolution, pixelRatio) {
        //            return this.getImageInternal(extent, resolution,
        //                pixelRatio, sourceProjection);
        //        }.bind(this));
        //        this.reprojectedRevision_ = this.getRevision();
        //
        //        return this.reprojectedImage_;
        //    }
        return 0;
    };
    
    
    /**
    * @abstract
    * @param {ol.Extent} extent Extent.
    * @param {number} resolution Resolution.
    * @param {number} pixelRatio Pixel ratio.
    * @param {ol.proj.Projection} projection Projection.
    * @return {ol.ImageBase} Single image.
    * @protected
    */
    virtual ol::ImageBase *getImageInternal(ol::Extent extent, ol::number_t resolution, ol::number_t pixelRatio, ol::proj::Projection projection) 
    {
        return 0;
    };
    
    
    /**
    * Handle image change events.
    * @param {ol.events.Event} event Event.
    * @protected
    */
    //void handleImageChange (ol::events::Event event) {
    //    var image = /** @type {ol.Image} */ (event.target);
    //    switch (image.getState()) {
    //    case ol.ImageState.LOADING:
    //        this.dispatchEvent(
    //            new ol.source.Image.Event(ol.source.Image.EventType_.IMAGELOADSTART,
    //                image));
    //        break;
    //    case ol.ImageState.LOADED:
    //        this.dispatchEvent(
    //            new ol.source.Image.Event(ol.source.Image.EventType_.IMAGELOADEND,
    //                image));
    //        break;
    //    case ol.ImageState.ERROR:
    //        this.dispatchEvent(
    //            new ol.source.Image.Event(ol.source.Image.EventType_.IMAGELOADERROR,
    //                image));
    //        break;
    //    default:
    //        // pass
    //    }
    //};


/**
* Default image load function for image sources that use ol.Image image
* instances.
* @param {ol.Image} image Image.
* @param {string} src Source.
*/
    static void defaultImageLoadFunction (ol::source::Source *image, std::string src) {
        //image.getImage().src = src;
    };
//
//
///**
//* @classdesc
//* Events emitted by {@link ol.source.Image} instances are instances of this
//* type.
//*
//* @constructor
//* @extends {ol.events.Event}
//* @implements {oli.source.ImageEvent}
//* @param {string} type Type.
//* @param {ol.Image} image The image.
//*/
//ol.source.Image.Event = function(type, image) {
//
//    ol.events.Event.call(this, type);
//
//    /**
//    * The image related to the event.
//    * @type {ol.Image}
//    * @api
//    */
//    this.image = image;
//
//};
//ol.inherits(ol.source.Image.Event, ol.events.Event);
//
//
///**
//* @enum {string}
//* @private
//*/
//ol.source.Image.EventType_ = {
//
//    /**
//    * Triggered when an image starts loading.
//    * @event ol.source.Image.Event#imageloadstart
//    * @api
//    */
//IMAGELOADSTART: 'imageloadstart',
//
//                /**
//                * Triggered when an image finishes loading.
//                * @event ol.source.Image.Event#imageloadend
//                * @api
//                */
//IMAGELOADEND: 'imageloadend',
//
//              /**
//              * Triggered if image loading results in an error.
//              * @event ol.source.Image.Event#imageloaderror
//              * @api
//              */
//IMAGELOADERROR: 'imageloaderror'
//
};
//

}
} // namespace

#endif
