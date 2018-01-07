//
//
//

// #include "ol.structs.PriorityQueue.test.h"

#include "gtest/gtest.h"

#include <ol/structs/PriorityQueue.h>

#include <functional>

struct priority_funct {
	int operator ( ) (int t)
	{
		return t;
	}
};

struct key_funct {
	std::string operator() (int t) {
		return std::to_string(t);
	}
};

template <class T>
class Foo : public std::vector<std::tuple<int, std::string, T> > {
	std::function<bool(typename T const &)> priority_;
	std::function<std::string(typename T const &)> key_;
	
public:
	Foo(std::function<bool(T)> const &priority, std::function<std::string(T)>key)
		: priority_(priority), key_(key)
	{}

	void add(T const &v) {
		int p = priority_(v);
		std::string k = key_(v);

		push_back(std::make_tuple(p, k, v));
	}
};

TEST(Foo, t1)
{
	Foo<int> foo = Foo<int>(priority_funct(), key_funct());

	foo.add(10);
	foo.add(20);
	foo.add(30);

	EXPECT_EQ(3, foo.size());
}

TEST(PriorityQueue, t1)
{
	{
		 auto pq = ol::structs::PriorityQueue<int, priority_funct, key_funct>(priority_funct(), key_funct());

		 pq.enqueue(42);

		 EXPECT_EQ(1, pq.getCount());
	}
	//{
	//	ol::structs::PriorityQueue<int> pq(priority_funct(), key_funct());
	//}
}
