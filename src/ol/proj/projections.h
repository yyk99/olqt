/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#ifndef OL_PROJ_PROJECTIONS_H
#define OL_PROJ_PROJECTIONS_H

#include <ol/exports.h>
#include <ol/proj/Projection.h>

#include <map>
#include <string>

namespace ol {
namespace proj {

class OLQT_EXPORT projections {
private:
    //goog.provide('ol.proj.projections');
    //
    //
    ///**
    // * @private
    // * @type {Object.<string, ol.proj.Projection>}
    // */
    //ol.proj.projections.cache_ = {};
    static std::map<std::string, Projection> cache_;
public:
    //
    //
    ///**
    // * Clear the projections cache.
    // */
    //ol.proj.projections.clear = function() {
    //  ol.proj.projections.cache_ = {};
    //};
    //
    //
    ///**
    // * Get a cached projection by code.
    // * @param {string} code The code for the projection.
    // * @return {ol.proj.Projection} The projection (if cached).
    // */
    static ol::proj::Projection get(std::string code);;
    //
    //
    /**
     * Add a projection to the cache.
     * @param {string} code The projection code.
     * @param {ol.proj.Projection} projection The projection to cache.
     */
    static void add (std::string code, Projection const &projection);;
};

}
}
#endif // OL_PROJ_PROJECTIONS_H
