//
// Copyright (c) 2018
// Use of this source code is governed by a license that
// can be found in the LICENSE file.
//

#include <ol/image.h>
#include <ol/extent.h>

void ol::Image::handleImageError_(void *obj, void *)
{
    ol::Image *self = reinterpret_cast<ol::Image *>(obj);
    self->state = ol::ImageState::ERROR;
    self->unlistenImage_();
    self->changed();
}

void ol::Image::handleImageLoad_(void *obj, void *)
{
    ol::Image *self = reinterpret_cast<ol::Image *>(obj);
    // TODO: implement
    //if (self->resolution == 0) {
    //    self->resolution = ol::extent::getHeight(self->extent) / self->image_->height;
    //}
    self->state = ol::ImageState::LOADED;
    self->unlistenImage_();
    self->changed();
}

void ol::Image::load()
{
    if (state == ol::ImageState::IDLE || state == ol::ImageState::ERROR) {
        state = ol::ImageState::LOADING;
        this->changed();
        imageListenerKeys_.push_back(
            ol::events::listenOnce(*image_, ol::events::EventType::ERROR, handleImageError_, this));
        imageListenerKeys_.push_back(
            ol::events::listenOnce(*image_, ol::events::EventType::LOAD, handleImageLoad_, this)
        );
        this->imageLoadFunction_(this, this->src_);
    }
}

void ol::Image::disposeInternal()
{
    delete image_;
}
