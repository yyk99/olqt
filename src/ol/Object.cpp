/*
 * Copyright (C) 2017 
 * All rights reserved.
 *
 */

#include "Object.h"

using namespace ol;

Object::Object()
{
}

Object::~Object()
{
}

property_val_t Object::get(std::string key)
{
    return values_[key];
}

void ol::Object::notify(std::string key, std::string oldValue)
{
    // TODO: implement

    //var eventType;
    //eventType = _ol_Object_.getChangeEventType(key);
    //this.dispatchEvent(new _ol_Object_.Event(eventType, key, oldValue));
    //eventType = ObjectEventType.PROPERTYCHANGE;
    //this.dispatchEvent(new _ol_Object_.Event(eventType, key, oldValue));
}

void ol::Object::set(std::string key, std::string value, bool opt_silent)
{
    if (opt_silent) {
        values_[key] = value;
    } else {
        auto oldValue = values_[key];
        values_[key] = value;
        if (oldValue != value) {
            notify(key, oldValue);
        }
    }
}

// end of file

