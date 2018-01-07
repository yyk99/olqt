//
//
//

#include "gtest/gtest.h"

#include <ol/Object.h>

TEST(t1, t1)
{
	ol::Object *o = new ol::Object();

	EXPECT_TRUE(o != 0);
}

#include <ol/events/EventTarget.h>

TEST(ol_events_EventTarget, t1)
{
	ol::events::EventTarget *et = new ol::events::EventTarget();
}

#include <ol/Tile.h>

TEST(ol_Tile, t1)
{
	ol::Tile *tile = new ol::Tile();
}