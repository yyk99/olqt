//
// Copyright (c) 2018
// Use of this source code is governed by a license that
// can be found in the LICENSE file.
//

#ifndef OL_SOURCE_STATE_H
#define OL_SOURCE_STATE_H

namespace ol {
namespace source {

struct State {
    enum enum_t {
        UNDEFINED,
        LOADING,
        READY,
        ERROR
    };
};

}
}

#endif
