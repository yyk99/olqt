/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#ifndef VIEW_H
#define VIEW_H

#include <ol/Object.h>

namespace ol {

///**
// * @module ol/View
// */
//import {DEFAULT_TILE_SIZE} from './tilegrid/common.js';
//import {inherits, getUid, nullFunction} from './index.js';
//import _ol_CenterConstraint_ from './CenterConstraint.js';
//import _ol_Object_ from './Object.js';
//import _ol_ResolutionConstraint_ from './ResolutionConstraint.js';
//import _ol_RotationConstraint_ from './RotationConstraint.js';
//import _ol_ViewHint_ from './ViewHint.js';
//import _ol_ViewProperty_ from './ViewProperty.js';
//import {linearFindNearest} from './array.js';
//import {assert} from './asserts.js';
//import _ol_coordinate_ from './coordinate.js';
//import {inAndOut} from './easing.js';
//import {getForViewAndSize, getCenter, getHeight, getWidth, isEmpty} from './extent.js';
//import GeometryType from './geom/GeometryType.js';
//import {fromExtent as polygonFromExtent} from './geom/Polygon.js';
//import SimpleGeometry from './geom/SimpleGeometry.js';
//import {clamp, modulo} from './math.js';
//import _ol_obj_ from './obj.js';
//import {createProjection, METERS_PER_UNIT} from './proj.js';
//import _ol_proj_Units_ from './proj/Units.js';
//
//
///**
// * @type {number} Default min zoom level for the map view.
// */
//var DEFAULT_MIN_ZOOM = 0;
//
//

/**
 * @classdesc
 * An ol.View object represents a simple 2D view of the map.
 *
 * This is the object to act upon to change the center, resolution,
 * and rotation of the map.
 *
 * ### The view states
 *
 * An `ol.View` is determined by three states: `center`, `resolution`,
 * and `rotation`. Each state has a corresponding getter and setter, e.g.
 * `getCenter` and `setCenter` for the `center` state.
 *
 * An `ol.View` has a `projection`. The projection determines the
 * coordinate system of the center, and its units determine the units of the
 * resolution (projection units per pixel). The default projection is
 * Spherical Mercator (EPSG:3857).
 *
 * ### The constraints
 *
 * `setCenter`, `setResolution` and `setRotation` can be used to change the
 * states of the view. Any value can be passed to the setters. And the value
 * that is passed to a setter will effectively be the value set in the view,
 * and returned by the corresponding getter.
 *
 * But an `ol.View` object also has a *resolution constraint*, a
 * *rotation constraint* and a *center constraint*.
 *
 * As said above, no constraints are applied when the setters are used to set
 * new states for the view. Applying constraints is done explicitly through
 * the use of the `constrain*` functions (`constrainResolution` and
 * `constrainRotation` and `constrainCenter`).
 *
 * The main users of the constraints are the interactions and the
 * controls. For example, double-clicking on the map changes the view to
 * the "next" resolution. And releasing the fingers after pinch-zooming
 * snaps to the closest resolution (with an animation).
 *
 * The *resolution constraint* snaps to specific resolutions. It is
 * determined by the following options: `resolutions`, `maxResolution`,
 * `maxZoom`, and `zoomFactor`. If `resolutions` is set, the other three
 * options are ignored. See documentation for each option for more
 * information.
 *
 * The *rotation constraint* snaps to specific angles. It is determined
 * by the following options: `enableRotation` and `constrainRotation`.
 * By default the rotation value is snapped to zero when approaching the
 * horizontal.
 *
 * The *center constraint* is determined by the `extent` option. By
 * default the center is not constrained at all.
 *
 * @constructor
 * @extends {ol.Object}
 * @param {olx.ViewOptions=} opt_options View options.
 * @api
 */

class OLQT_EXPORT View : public Object {
public:
    View();
    ~View();
};
//export default _ol_View_;

} // namespace
#endif // VIEW_H
