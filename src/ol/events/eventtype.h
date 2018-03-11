//
// Copyright (c) 2018
// Use of this source code is governed by a license that
// can be found in the LICENSE file.
//

#ifndef OL_EVENTS_EVENTTYPE_H
#define OL_EVENTS_EVENTTYPE_H

namespace ol {
namespace events {

//goog.provide('ol.events.EventType');
//
///**
// * @enum {string}
// * @const
// */
struct EventType {
//  /**
//   * Generic change event. Triggered when the revision counter is increased.
//   * @event ol.events.Event#change
//   * @api
//   */

    enum enum_t {
          CHANGE,
          CLEAR,
          CLICK,
          DBLCLICK,
          DRAGENTER,
          DRAGOVER,
          DROP,
          ERROR,
          KEYDOWN,
          KEYPRESS,
          LOAD,
          MOUSEDOWN,
          MOUSEMOVE,
          MOUSEOUT,
          MOUSEUP,
          MOUSEWHEEL,
          MSPOINTERDOWN,
          RESIZE,
          TOUCHSTART,
          TOUCHMOVE,
          TOUCHEND,
          WHEEL,
    };
};

}
}

#endif
