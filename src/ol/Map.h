/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#ifndef MAP_H
#define MAP_H

#include <vector>

#include "exports.h"

#include "ol/forward_definitions.h"
#include "PluggableMap.h"

class QWindow;

namespace ol {


class OLQT_EXPORT Map : public PluggableMap {
public:
    Map();
    virtual ~Map();
};
}
#endif // MAP_H
