//
// Copyright (c) 2018
// Use of this source code is governed by a license that
// can be found in the LICENSE file.
//

#ifndef OL_IMAGESTATE_H
#define OL_IMAGESTATE_H

namespace ol {
struct ImageState {
    enum enum_t {
        IDLE = 0,
        LOADING = 1,
        LOADED = 2,
        ERROR = 3
    };
};
}

#endif
