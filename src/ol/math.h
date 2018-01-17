/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#ifndef OL_MATH_H
#define OL_MATH_H

// Based on 4.6.4

#include <ol/typedefs.h>
#include <ol/exports.h>

#include <stdexcept>
#include <algorithm>
#include <limits>
#include <cmath>

#define Infinity std::numeric_limits<ol::number_t>::infinity()

#ifndef PI
#   define PI 3.1415926535897932384626433
#endif

namespace ol {
namespace math {

///**
// * @module ol/math
// */
//import {assert} from './asserts.js';
//
///**
// * Takes a number and clamps it to within the provided bounds.
// * @param {number} value The input number.
// * @param {number} min The minimum value to return.
// * @param {number} max The maximum value to return.
// * @return {number} The input number if it is within bounds, or the nearest
// *     number within the bounds.
// */
//export function clamp(value, min, max) {
//  return Math.min(Math.max(value, min), max);
//}

template <class T>
T clamp(T _v, T _min, T _max) {
    return std::min(std::max(_v, _min), _max);
}

/**
 * Return the hyperbolic cosine of a given number. The method will use the
 * native `Math.cosh` function if it is available, otherwise the hyperbolic
 * cosine will be calculated via the reference implementation of the Mozilla
 * developer network.
 *
 * @param {number} x X.
 * @return {number} Hyperbolic cosine of x.
 */

inline ol::number_t cosh(ol::number_t d)
{
	return std::cosh(d);
}

/**
 * @param {number} x X.
 * @return {number} The smallest power of two greater than or equal to x.
 */
inline ol::number_t roundUpToPowerOfTwo(ol::number_t x) 
{
	//assert(0 < x, 29); // `x` must be greater than `0`
	if (x <= 0)
		throw std::logic_error("x is not positive");
	return std::pow(2, std::ceil(std::log(x) / 0.693147180559945309417232121458));
}

//
//
///**
// * Returns the square of the closest distance between the point (x, y) and the
// * line segment (x1, y1) to (x2, y2).
// * @param {number} x X.
// * @param {number} y Y.
// * @param {number} x1 X1.
// * @param {number} y1 Y1.
// * @param {number} x2 X2.
// * @param {number} y2 Y2.
// * @return {number} Squared distance.
// */
//export function squaredSegmentDistance(x, y, x1, y1, x2, y2) {
//  var dx = x2 - x1;
//  var dy = y2 - y1;
//  if (dx !== 0 || dy !== 0) {
//    var t = ((x - x1) * dx + (y - y1) * dy) / (dx * dx + dy * dy);
//    if (t > 1) {
//      x1 = x2;
//      y1 = y2;
//    } else if (t > 0) {
//      x1 += dx * t;
//      y1 += dy * t;
//    }
//  }
//  return squaredDistance(x, y, x1, y1);
//}

///**
// * Returns the square of the distance between the points (x1, y1) and (x2, y2).
// * @param {number} x1 X1.
// * @param {number} y1 Y1.
// * @param {number} x2 X2.
// * @param {number} y2 Y2.
// * @return {number} Squared distance.
// */
//export function squaredDistance(x1, y1, x2, y2) {
//  var dx = x2 - x1;
//  var dy = y2 - y1;
//  return dx * dx + dy * dy;
//}


/**
 * Solves system of linear equations using Gaussian elimination method.
 *
 * @param {Array.<Array.<number>>} mat Augmented matrix (n x n + 1 column)
 *                                     in row-major order.
 * @return {Array.<number>} The resulting vector.
 */
std::vector<number_t> OLQT_EXPORT solveLinearSystem(std::vector<std::vector<number_t> > &mat);

/**
 * Converts radians to to degrees.
 *
 * @param {number} angleInRadians Angle in radians.
 * @return {number} Angle in degrees.
 */
inline ol::number_t toDegrees(ol::number_t angleInRadians) {
  return angleInRadians * 180 / PI;
}

/**
 * Converts degrees to radians.
 *
 * @param {number} angleInDegrees Angle in degrees.
 * @return {number} Angle in radians.
 */
inline ol::number_t toRadians(ol::number_t angleInDegrees) {
	return angleInDegrees * PI / 180;
}

/**
 * Returns the modulo of a / b, depending on the sign of b.
 *
 * @param {number} a Dividend.
 * @param {number} b Divisor.
 * @return {number} Modulo.
 */
inline int modulo(int a, int b) {
	int r = a % b;
	return r * b < 0 ? r + b : r;
}

/**
 * Calculates the linearly interpolated value of x between a and b.
 *
 * @param {number} a Number
 * @param {number} b Number
 * @param {number} x Value to be interpolated.
 * @return {number} Interpolated value.
 */
inline ol::number_t lerp(ol::number_t a, ol::number_t b, ol::number_t x) {
	return a + x * (b - a);
}

}
}

#endif // OL_MATH_H
