#include "../../catch.hpp"
#include "../LinkedList/LinkedListAlgorithms.h"

namespace LinkedListTestHelpers
{
	std::vector<int> linkedListToVector(LinkedList* node)
	{
		std::vector<int> arr;

		while (node)
		{
			arr.push_back(node->val);
			node = node->next;
		}

		return arr;
	}
}

TEST_CASE("Linked List Delete Node Tests")
{	
	std::vector<int> arr = { 0, 2, 4, 6, 8, 9, 11 };
	auto* head = new LinkedList(arr[0]);
	auto* node = head;

	for(int i = 1; i < arr.size(); ++i)
	{
		node->next = new LinkedList(arr[i]);
		node = node->next;
	}

	SECTION("Delete Non Existant Number")
	{
		auto* resultNode = LinkedListAlgorithms::deleteNode(head, 12);
		REQUIRE(LinkedListTestHelpers::linkedListToVector(resultNode) == arr);
	}

	SECTION("Delete first node tests")
	{
		auto* resultNode = LinkedListAlgorithms::deleteNode(head, 0);
		std::vector<int> resultArr = { 2, 4, 6, 8, 9, 11 };
		REQUIRE(LinkedListTestHelpers::linkedListToVector(resultNode) == resultArr);
	}

	SECTION("Delete Middle Node")
	{
		auto* resultNode = LinkedListAlgorithms::deleteNode(head, 6);
		std::vector<int> resultArr = {0, 2, 4, 8, 9, 11 };
		REQUIRE(LinkedListTestHelpers::linkedListToVector(resultNode) == resultArr);
	}

	SECTION("Delete Last Node")
	{
		auto* resultNode = LinkedListAlgorithms::deleteNode(head, 11);
		std::vector<int> resultArr = { 0, 2, 4, 6, 8, 9};
		REQUIRE(LinkedListTestHelpers::linkedListToVector(resultNode) == resultArr);
	}	
}

TEST_CASE("Linked List Reverse Test")
{
	std::vector<int> arr = { 0, 2, 4, 6, 8, 9, 11 };
	auto* head = new LinkedList(arr[0]);
	auto* node = head;

	for (int i = 1; i < arr.size(); ++i)
	{
		node->next = new LinkedList(arr[i]);
		node = node->next;
	}

	auto* resultLinkedList = LinkedListAlgorithms::reverseLinkedList(head);
	std::vector<int> resultArr = {11, 9, 8, 6, 4, 2, 0};
	REQUIRE(LinkedListTestHelpers::linkedListToVector(resultLinkedList) == resultArr);
	
}

TEST_CASE("Linked List Sum Two Number Tests")
{
	std::vector<int> arr1 = { 2, 4, 3 };
	std::vector<int> arr2 = { 5, 6 ,4 };
	const std::vector<int> resultArr = { 7, 0, 8 };

	auto* node1 = new LinkedList(arr1[0]);
	auto* dumm1 = node1;
	auto* node2 = new LinkedList(arr2[0]);
	auto* dumm2 = node2;

	for (int i = 1; i < arr1.size(); ++i)
	{
		dumm1->next = new LinkedList(arr1[i]);
		dumm1 = dumm1->next;
	}

	for (int i = 1; i < arr2.size(); ++i)
	{
		dumm2->next = new LinkedList(arr2[i]);
		dumm2 = dumm2->next;
	}

	auto* resultLinkedList = LinkedListAlgorithms::addTwoNumbers(node1, node2);
	REQUIRE(LinkedListTestHelpers::linkedListToVector(resultLinkedList) == resultArr);
}