//
// Copyright (c) 2018
// Use of this source code is governed by a license that
// can be found in the LICENSE file.
//

#ifndef OL_IMAGEBASE_H
#define OL_IMAGEBASE_H

#include <ol/typedefs.h>
#include <ol/events/EventTarget.h>
#include <ol/imagestate.h>

//goog.provide('ol.ImageBase');
//
//goog.require('ol');
//goog.require('ol.events.EventTarget');
//goog.require('ol.events.EventType');
//
//

namespace ol {
class Image;

/**
 * @constructor
 * @abstract
 * @extends {ol.events.EventTarget}
 * @param {ol.Extent} extent Extent.
 * @param {number|undefined} resolution Resolution.
 * @param {number} pixelRatio Pixel ratio.
 * @param {ol.ImageState} state State.
 */
class ImageBase : public events::EventTarget {
private:
    ol::number_t pixelRatio_;
protected:
    ol::Extent extent;
    ol::number_t resolution;
    ol::ImageState::enum_t state;
public:
    ImageBase(ol::Extent const &extent, ol::number_t resolution, ol::number_t pixelRatio, ol::ImageState::enum_t state) 
        : extent(extent), resolution(resolution), pixelRatio_(pixelRatio), state(state)
    {
        //
        //  ol.events.EventTarget.call(this);
        //
        //  /**
        //   * @protected
        //   * @type {ol.Extent}
        //   */
        //  this.extent = extent;
        //
        //  /**
        //   * @private
        //   * @type {number}
        //   */
        //  this.pixelRatio_ = pixelRatio;
        //
        //  /**
        //   * @protected
        //   * @type {number|undefined}
        //   */
        //  this.resolution = resolution;
        //
        //  /**
        //   * @protected
        //   * @type {ol.ImageState}
        //   */
        //  this.state = state;
        //
    };
    //ol.inherits(ol.ImageBase, ol.events.EventTarget);


    ///**
    // * @protected
    // */
    void changed () {
    //  this.dispatchEvent(ol.events.EventType.CHANGE);
    };
    //
    //
    ///**
    // * @return {ol.Extent} Extent.
    // */
    ol::Extent getExtent () const {
        return extent;
    };
    
    
    /**
     * @abstract
     * @return {HTMLCanvasElement|Image|HTMLVideoElement} Image.
     */

    virtual ol::Image *getImage() const = 0;
    
    /**
     * @return {number} PixelRatio.
     */
    ol::number_t getPixelRatio() {
        return pixelRatio_;
    };
    
    
    /**
     * @return {number} Resolution.
     */
    ol::number_t getResolution () {
      return /** @type {number} */ resolution;
    };
    
    
    /**
     * @return {ol.ImageState} State.
     */
    int getState () const {
      return state;
    };
    
    
    /**
     * Load not yet loaded URI.
     * @abstract
     */
    virtual void load() = 0;
};

} // namespace ol

#endif
