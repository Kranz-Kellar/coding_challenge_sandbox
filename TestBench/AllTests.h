#pragma once
#include "..//..//mem/Allocator.h"
#include <util/UniqueId.h>
#include "testing.hpp"

const char* Logger::logFileName = "log.txt";
bool Logger::consoleLog = true;
unsigned int UniqueId::nextId = 0;

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
		Allocator alloc(1024);
		ASSERT_EQUAL(alloc.getAmountOfMaxSpace(), 1024);
	}
public:

	void run() override {
		allocatorCtorTest();
	}
};


REGISTER_TEST(UniqueIdTest, "Unique Id testing");
REGISTER_TEST(AllocatorTest, "Test of base allocator");
