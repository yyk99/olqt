/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#include "Units.h"
#include <stdexcept>

#ifndef PI
#   define PI 3.1415926535897932384626433
#endif

double ol::proj::Units::METERS_PER_UNIT(enum_t key)
{
    switch(key) {
    // use the radius of the Normal sphere
    case DEGREES:
        return 2 * PI * 6370997 / 360;
    case FEET:
        return 0.3048;
    case METERS:
        return 1;
    case USFEET:
        return 1200 / 3937;
    }

    throw std::runtime_error("Unknown unit");
}
