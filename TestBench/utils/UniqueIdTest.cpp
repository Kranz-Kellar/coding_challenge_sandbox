#pragma once
#include "UniqueIdTest.h"

void UniqueIdTest::getNextIdTest() {
	UniqueId testId;
	ASSERT_EQUAL(testId.id, 1);
}

void UniqueIdTest::uniqueIdComparisonTest() {
	UniqueId testId1;
	UniqueId testId2;

	ASSERT_FALSE(testId1 == testId2);
	ASSERT_TRUE(testId1 == testId1);
}

void UniqueIdTest::run() {
	getNextIdTest();
	uniqueIdComparisonTest();
}