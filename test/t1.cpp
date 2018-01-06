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

