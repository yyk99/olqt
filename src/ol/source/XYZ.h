/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#ifndef OL_SOURCE_XYZ_H
#define OL_SOURCE_XYZ_H

#include <string>

#include "TileImage.h"

namespace ol {
namespace source {

class OLQT_EXPORT XYZ : public TileImage {
public:
    XYZ(std::string const &url);
    ~XYZ();
};

}
}

#endif // XYZ_H
