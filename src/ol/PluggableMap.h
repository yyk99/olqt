/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#ifndef OL_PLUGGABLEMAP_H
#define OL_PLUGGABLEMAP_H

#include <ol/forward_definitions.h>
#include <ol/Object.h>

class QWidget;

namespace ol {

class OLQT_EXPORT PluggableMap {
public:
    PluggableMap();
    ~PluggableMap();

    virtual void setTarget(std::string const &targetName);
    virtual void setTarget(QWidget *widget);
    virtual void addLayer(ol::layer::Layer *layers);
    virtual void setView(ol::View *view);
};

}
#endif // PLUGGABLEMAP_H
