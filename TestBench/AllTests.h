#pragma once
#include "..//..//mem/Allocator.h"
#include <util/UniqueId.h>
#include "testing.hpp"

const char* Logger::logFileName = "log.txt";
bool Logger::consoleLog = false;
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
	void CtorTest() {
		Allocator alloc(512);
		ASSERT_EQUAL(alloc.getAmountOfMaxSpace(), 512);
	}

	void AllocTest() {
		Allocator alloc(512);
		alloc.allocate(256);

		ASSERT_EQUAL(alloc.getAmountOfFreeSpace(), 256);
	}

	void FreeTest() {
		Allocator alloc(512);
		alloc.allocate(256);
		alloc.free(256);
		ASSERT_EQUAL(alloc.getAmountOfFreeSpace(), 512);
	}

	void GetNewMemoryTest() {
		Allocator alloc(512);
		alloc.getNewMemory(1024);
		ASSERT_EQUAL(alloc.getAmountOfMaxSpace(), 512);

		alloc.freeAllMemory();
		alloc.getNewMemory(1024);
		ASSERT_EQUAL(alloc.getAmountOfMaxSpace(), 1024);
	}

	void FreeAllMemoryTest() {
		Allocator alloc(512);
		alloc.freeAllMemory();
		ASSERT_EQUAL(alloc.getAmountOfMaxSpace(), 0);
	}

public:

	void run() override {
		CtorTest();
		AllocTest();
		FreeTest();
		GetNewMemoryTest();
		FreeAllMemoryTest();
	}
};


REGISTER_TEST(UniqueIdTest, "Unique Id testing");
REGISTER_TEST(AllocatorTest, "Test of base allocator");
