/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#ifndef OL_PROJ_UNITS_H
#define OL_PROJ_UNITS_H

namespace ol {
namespace proj {

class Units {
public:
    //goog.provide('ol.proj.Units');
/**
 * Projection units: `'degrees'`, `'ft'`, `'m'`, `'pixels'`, `'tile-pixels'` or
 * `'us-ft'`.
 * @enum {string}
 */
    enum enum_t {
        DEGREES, // 'degrees',
        FEET, // 'ft',
        METERS, // 'm',
        PIXELS, // 'pixels',
        TILE_PIXELS, // 'tile-pixels',
        USFEET, // 'us-ft'
    };

/**
 * Meters per unit lookup table.
 * @const
 * @type {Object.<ol.proj.Units, number>}
 * @api
 */
    static double METERS_PER_UNIT(enum_t key);
};

}
}

#endif // OL_PROJ_UNITS_H
