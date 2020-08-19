//
// Copyright (c) 2018
// Use of this source code is governed by a license that
// can be found in the LICENSE file.
//

#include <ol/source/Image.h>
#include <ol/array.h>

using namespace ol::source;

ol::number_t Image::findNearestResolution(ol::number_t resolution)
{
    if (resolutions_.size()) {
        int idx = ol::array::linearFindNearest(resolutions_, resolution, 0);
        resolution = resolutions_[idx];
    }
    return resolution;
}
