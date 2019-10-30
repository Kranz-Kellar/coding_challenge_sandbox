#pragma once
#include "..//..//mem/Allocator.h"
#include <util/UniqueId.h>
#include <testing.hpp>

struct UniqueIdTest : TestCase
{
	void getNextIdTest() {
		UniqueId testId;
		ASSERT_EQUAL(testId.id, 1);
	}


	void uniqueIdComparisonTest() {
		UniqueId testId1;
		UniqueId testId2;

		ASSERT_FALSE(testId1 == testId2);
		ASSERT_TRUE(testId1 == testId1);
	}

public:
	void run() override {
		getNextIdTest();
		uniqueIdComparisonTest();
	}
};

struct AllocatorTest : TestCase
{
	void allocatorCtorTest() {
		Allocator alloc(520);

		ASSERT_EQUAL(sizeof(alloc.getAmountOfMaxSpace()), 520);
	}
public:

	void run() override {
		allocatorCtorTest();
	}
};


REGISTER_TEST(UniqueIdTest, "Unique Id testing");
REGISTER_TEST(AllocatorTest, "Test of base allocator");
