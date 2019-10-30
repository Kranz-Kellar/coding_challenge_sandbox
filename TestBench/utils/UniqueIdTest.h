#pragma once

#include <util/UniqueId.h>
#include <testing.hpp>

struct UniqueIdTest : TestCase
{
	void getNextIdTest();

	void uniqueIdComparisonTest();

public:
	void run() override;
};

REGISTER_TEST(UniqueIdTest, "Unique Id testing");
