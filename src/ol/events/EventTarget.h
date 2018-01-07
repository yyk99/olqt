//
//
//

#ifndef OL_EVENTS_EVENTTARGET_H
#define OL_EVENTS_EVENTTARGET_H

#include <ol/Disposable.h>

namespace ol {
namespace events {

class OLQT_EXPORT EventTarget : public ol::Disposable {
public:
	EventTarget();
	virtual ~EventTarget();

protected:
	virtual void disposeInternal() override;
};

}
}

#endif
