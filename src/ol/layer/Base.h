//
//
//

#ifndef LAYER_BASE_H
#define LAYER_BASE_H

#pragma warning ( disable : 4251 )

#include <ol/Object.h>

namespace ol {
namespace layer {

class OLQT_EXPORT Base : public ol::Object {
public:
    Base();
    ~Base();
};

}
}

#endif

// end of file