/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#include "projections.h"

std::map<std::string, ol::proj::Projection> ol::proj::projections::cache_;

ol::proj::Projection ol::proj::projections::get(std::string code)
{
    return cache_[code];
}

void ol::proj::projections::add(std::string code, Projection const &projection)
{
    cache_[code] = projection;
}
