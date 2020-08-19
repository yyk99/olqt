/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#ifndef TILE_H
#define TILE_H

#include "Layer.h"

#include <ol/forward_definitions.h>

namespace ol {
namespace layer {

class OLQT_EXPORT Tile : public Layer {
public:
    Tile(ol::source::Source *source = 0);
    ~Tile();

private:
    ol::source::SourcePtr m_source;
};

}
}


#endif // TILE_H
