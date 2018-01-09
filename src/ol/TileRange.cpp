/*
 * Copyright (C) 2018
 * All rights reserved.
 *
 */

#include "TileRange.h"

ol::TileRange ol::TileRange::createOrUpdate(int minX, int maxX, int minY, int maxY)
{
	//TileRange.createOrUpdate = function(minX, maxX, minY, maxY, tileRange) {
	//  if (tileRange !== undefined) {
	//    tileRange.minX = minX;
	//    tileRange.maxX = maxX;
	//    tileRange.minY = minY;
	//    tileRange.maxY = maxY;
	//    return tileRange;
	//  } else {
	//    return new TileRange(minX, maxX, minY, maxY);
	//  }

	return TileRange(minX, maxX, minY, maxY);
}
