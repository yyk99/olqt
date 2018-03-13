//
// Copyright (c) 2018
// Use of this source code is governed by a license that
// can be found in the LICENSE file.
//

#include <ol/events/EventTarget.h>

#include <string>

#include <ol/events.h>

ol::EventsKey ol::events::listen(EventTarget &target, EventType::enum_t type, void(*listener)(void *, void *), void *opt_this /*= 0*/, bool once /*= false*/)
{
    //  var listenerMap = ol.events.getListenerMap_(target);
    //  var listeners = listenerMap[type];
    //  if (!listeners) {
    //    listeners = listenerMap[type] = [];
    //  }
    //  var listenerObj = ol.events.findListener_(listeners, listener, opt_this,
    //      false);
    //  if (listenerObj) {
    //    if (!opt_once) {
    //      // Turn one-off listener into a permanent one.
    //      listenerObj.callOnce = false;
    //    }
    //  } else {
    //    listenerObj = /** @type {ol.EventsKey} */ ({
    //      bindTo: opt_this,
    //      callOnce: !!opt_once,
    //      listener: listener,
    //      target: target,
    //      type: type
    //    });
    //    target.addEventListener(type, ol.events.bindListener_(listenerObj));
    //    listeners.push(listenerObj);
//  }
        //
        //  return listenerObj;

    return ol::EventsKey();
}

ol::EventsKey ol::events::listenOnce(EventTarget &target, EventType::enum_t type, void(*listener)(void *, void *), void *opt_this)
{
    return ol::events::listen(target, type, listener, opt_this, true);
}
