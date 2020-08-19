/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#ifndef OL_EXTENT_CORNER_H
#define OL_EXTENT_CORNER_H

#include <ol/exports.h>

namespace ol {
namespace extent {

/**
 * @module ol/extent/Corner
 */

/**
 * Extent corner.
 * @enum {string}
 */
class Corner {
public:
    enum enum_t {
        BOTTOM_LEFT, // : 'bottom-left',
        BOTTOM_RIGHT, // : 'bottom-right',
        TOP_LEFT, // : 'top-left',
        TOP_RIGHT, // : 'top-right'
    };
};

}
}

#endif // OL_EXTENT_CORNER_H
