#include "../../../../Catch2/single_include/catch2/catch.hpp"
#include "../BinarySearch/BinarySearchHelpers.h"
#include "../BinarySearch/BSAlgorithms.cpp"

TEST_CASE("Simple Binary Search Tests")
{
	SECTION("Simple Int Array Test")
	{
		int a[15]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 , 13, 14, 15 };
		auto size = sizeof(a) / sizeof(a[0]) - 1;
		auto result = recursiveBinarySearch<int, int>(a, 0, size, 4);
		REQUIRE(result == 3);
	}

	SECTION("Simple Char Array Test")
	{
		char a[5]{ 'a', 'b', 'c', 'd', 'e' };
		auto size = sizeof(a) / sizeof(a[0]) - 1;
		auto result = recursiveBinarySearch<char, int>(a, 0, size, 'd');
		REQUIRE(result == 3);
	}
}

TEST_CASE("Pivoted Binary Search Tests")
{
	SECTION("Not Present")
	{
		int a[7]{4, 5, 6, 7, 1, 2, 3};
		auto size = sizeof(a) / sizeof(a[0]);
		auto p = findPivot<int, int>(a, 0, size);
		REQUIRE(p == 3);
		auto result = pivotedRecursiveBinarySearch<int, int>(a, 0, size, 8);
		REQUIRE(result == -1);
	}

	SECTION("Pivot Found")
	{
		int a[7]{ 4, 5, 6, 7, 1, 2, 3 };
		auto size = sizeof(a) / sizeof(a[0]) - 1;
		auto p = findPivot<int, int>(a, 0, size);
		REQUIRE(p == 3);
		auto result = pivotedRecursiveBinarySearch<int, int>(a, 0, size, 2);
		REQUIRE(result == 5);
	}
}