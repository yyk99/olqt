/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#ifndef FORWARD_DEFINITIONS_H
#define FORWARD_DEFINITIONS_H

#include <memory>

namespace ol {

class Map;
typedef std::shared_ptr<Map> MapPtr;

class View;
typedef std::shared_ptr<View> ViewPtr;

namespace layer {
class Layer;
typedef std::shared_ptr<Layer> LayerPtr;
}

namespace source {
class Source;
typedef std::shared_ptr<Source> SourcePtr;
}

}

#endif // FORWARD_DEFINITIONS_H
