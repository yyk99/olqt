//
//
//

#ifndef OL_DISPOSABLE_H
#define OL_DISPOSABLE_H

#include "exports.h"

namespace ol {

class OLQT_EXPORT Disposable {
public:
	Disposable();
	virtual ~Disposable();

	virtual void dispose();

protected:
	virtual void disposeInternal() = 0;
private:
	bool disposed_;
};

}

#endif
