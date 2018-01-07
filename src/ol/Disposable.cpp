//
//
//

#include "Disposable.h"

ol::Disposable::Disposable() : disposed_(false)
{
}

ol::Disposable::~Disposable()
{
	dispose();
}

void ol::Disposable::dispose()
{
	if (!disposed_) {
		disposed_ = true;

		disposeInternal();
	}
}
