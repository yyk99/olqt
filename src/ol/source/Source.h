//
//
//

#ifndef OL_SOURCE_SOURCE_H
#define OL_SOURCE_SOURCE_H

#include <ol/Object.h>

namespace ol {
namespace source {

///**
// * @module ol/source/Source
// */
//import {inherits, nullFunction} from '../index.js';
//import _ol_Object_ from '../Object.js';
//import {get as getProjection} from '../proj.js';
//import SourceState from '../source/State.js';
//
//
///**
// * @classdesc
// * Abstract base class; normally only used for creating subclasses and not
// * instantiated in apps.
// * Base class for {@link ol.layer.Layer} sources.
// *
// * A generic `change` event is triggered when the state of the source changes.
// *
// * @constructor
// * @abstract
// * @extends {ol.Object}
// * @param {ol.SourceSourceOptions} options Source options.
// * @api
// */
//var Source = function(options) {

class OLQT_EXPORT Source : public ol::Object {

//
//  _ol_Object_.call(this);
//
//  /**
//   * @private
//   * @type {ol.proj.Projection}
//   */
//  this.projection_ = getProjection(options.projection);
//
//  /**
//   * @private
//   * @type {?ol.Attribution}
//   */
//  this.attributions_ = this.adaptAttributions_(options.attributions);
//
//  /**
//   * @private
//   * @type {ol.source.State}
//   */
//  this.state_ = options.state !== undefined ?
//    options.state : SourceState.READY;
//
//  /**
//   * @private
//   * @type {boolean}
//   */
//  this.wrapX_ = options.wrapX !== undefined ? options.wrapX : false;
//
//};
//
//inherits(Source, _ol_Object_);
//
///**
// * Turns the attributions option into an attributions function.
// * @param {ol.AttributionLike|undefined} attributionLike The attribution option.
// * @return {?ol.Attribution} An attribution function (or null).
// */
//Source.prototype.adaptAttributions_ = function(attributionLike) {
//  if (!attributionLike) {
//    return null;
//  }
//  if (Array.isArray(attributionLike)) {
//    return function(frameState) {
//      return attributionLike;
//    };
//  }
//
//  if (typeof attributionLike === 'function') {
//    return attributionLike;
//  }
//
//  return function(frameState) {
//    return [attributionLike];
//  };
//};
//
///**
// * @param {ol.Coordinate} coordinate Coordinate.
// * @param {number} resolution Resolution.
// * @param {number} rotation Rotation.
// * @param {number} hitTolerance Hit tolerance in pixels.
// * @param {Object.<string, boolean>} skippedFeatureUids Skipped feature uids.
// * @param {function((ol.Feature|ol.render.Feature)): T} callback Feature
// *     callback.
// * @return {T|undefined} Callback result.
// * @template T
// */
//Source.prototype.forEachFeatureAtCoordinate = nullFunction;
//
//
///**
// * Get the attribution function for the source.
// * @return {?ol.Attribution} Attribution function.
// */
//Source.prototype.getAttributions = function() {
//  return this.attributions_;
//};
//
//
///**
// * Get the projection of the source.
// * @return {ol.proj.Projection} Projection.
// * @api
// */
//Source.prototype.getProjection = function() {
//  return this.projection_;
//};
//
//
///**
// * @abstract
// * @return {Array.<number>|undefined} Resolutions.
// */
//Source.prototype.getResolutions = function() {};
//
//
///**
// * Get the state of the source, see {@link ol.source.State} for possible states.
// * @return {ol.source.State} State.
// * @api
// */
//Source.prototype.getState = function() {
//  return this.state_;
//};
//
//
///**
// * @return {boolean|undefined} Wrap X.
// */
//Source.prototype.getWrapX = function() {
//  return this.wrapX_;
//};
//
//
///**
// * Refreshes the source and finally dispatches a 'change' event.
// * @api
// */
//Source.prototype.refresh = function() {
//  this.changed();
//};
//
//
///**
// * Set the attributions of the source.
// * @param {ol.AttributionLike|undefined} attributions Attributions.
// *     Can be passed as `string`, `Array<string>`, `{@link ol.Attribution}`,
// *     or `undefined`.
// * @api
// */
//Source.prototype.setAttributions = function(attributions) {
//  this.attributions_ = this.adaptAttributions_(attributions);
//  this.changed();
//};
//
//
///**
// * Set the state of the source.
// * @param {ol.source.State} state State.
// * @protected
// */
//Source.prototype.setState = function(state) {
//  this.state_ = state;
//  this.changed();
//};
};
//export default Source;

}
}

#endif // OL_SOURCE_SOURCE_H
