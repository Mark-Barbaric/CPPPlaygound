#include "include/catch.hpp"
#include "../../Algorithms/LinkedList/LinkedListAlgorithms.h"

TEST_CASE("Linked List Base Functionality Tests")
{	
	LinkedList<int> linkedList;
	linkedList.insertNode(0);
	linkedList.insertNode(2);
	linkedList.insertNode(6);
	linkedList.insertNode(8);
	linkedList.insertNode(9);
	linkedList.insertNode(11);

	REQUIRE(linkedList.containsNode(2) == true);
	REQUIRE(linkedList.containsNode(52) == false);
	
	SECTION("Delete Non Existant Number")
	{
		std::string ans = "0 2 6 8 9 11";
		linkedList.deleteNode(12);
		REQUIRE(linkedList.traverseNodes() == ans);
	}

	SECTION("Delete first node tests")
	{
		std::string ans = "2 6 8 9 11";
		linkedList.deleteNode(0);
		REQUIRE(linkedList.traverseNodes() == ans);
	}

	SECTION("Delete Middle Node")
	{
		std::string ans = "0 2 8 9 11";
		linkedList.deleteNode(6);
		REQUIRE(linkedList.traverseNodes() == ans);
	}

	SECTION("Delete Last Node")
	{
		std::string ans = "0 2 6 8 9";
		linkedList.deleteNode(11);
		REQUIRE(linkedList.traverseNodes() == ans);
	}	
}

TEST_CASE("Linked List Algorithm Tests")
{
	LinkedList<int> linkedList;
	linkedList.insertNode(0);
	linkedList.insertNode(2);
	linkedList.insertNode(4);
	linkedList.insertNode(6);
	linkedList.insertNode(8);
	linkedList.insertNode(9);
	linkedList.insertNode(11);

	auto* curHead = linkedList.getHeadNode();
	auto* reversedHead = LinkedListAlgorithms::reverseLinkedList(curHead);
	std::string ans = "11 9 8 6 4 2 0";
	REQUIRE(LinkedListAlgorithms::traverseNodesUtil(reversedHead) == ans);
}

TEST_CASE("Linked List Cycle Tests")
{

	SECTION("Cycle Test 1")
	{
		ListNode<int>* head = new ListNode<int>(3);
		ListNode<int>* cycleRoot = new ListNode<int>(2);
		head->next = cycleRoot;
		head->next->next = new ListNode<int>(0);
		head->next->next->next = new ListNode<int>(-4);
		REQUIRE(LinkedListAlgorithms::findCycleIntersection(head) == nullptr);
		head->next->next->next->next = cycleRoot;
		REQUIRE(LinkedListAlgorithms::findCycleIntersection(head) == cycleRoot);
	}

	SECTION("Cycle Test 2")
	{
		ListNode<int>* head = new ListNode<int>(1);
		head->next = new ListNode<int>(2);
		REQUIRE(LinkedListAlgorithms::findCycleIntersection(head) == nullptr);
		head->next->next = head;
		REQUIRE(LinkedListAlgorithms::findCycleIntersection(head) == head);
	}
}

//
//TEST_CASE("Linked List Sum Two Number Tests")
//{
//	SECTION("Sum Two Numbers Tests")
//	{
//		std::vector<int> arr1 = { 2, 4, 3 };
//		std::vector<int> arr2 = { 5, 6 ,4 };
//		const std::vector<int> resultArr = { 7, 0, 8 };
//
//		auto* node1 = LinkedListTestHelpers::vectorToLinkedList(arr1);
//		auto* node2 = LinkedListTestHelpers::vectorToLinkedList(arr2);
//
//		auto* resultLinkedList = LinkedListAlgorithms::addTwoNumbers(node1, node2);
//		REQUIRE(LinkedListTestHelpers::linkedListToVector(resultLinkedList) == resultArr);
//	}
//
//	SECTION("Sum Two Numbers Tests Two")
//	{
//		std::vector<int> arr1 = { 7, 2, 4, 3};
//		std::vector<int> arr2 = { 5, 6 ,4 };
//		const std::vector<int> resultArr = { 7, 8, 0, 7 };
//
//		auto* node1 = LinkedListTestHelpers::vectorToLinkedList(arr1);
//		auto* node2 = LinkedListTestHelpers::vectorToLinkedList(arr2);
//
//		auto* resultLinkedList = LinkedListAlgorithms::addTwoNumbersTwo(node1, node2);
//		REQUIRE(LinkedListTestHelpers::linkedListToVector(resultLinkedList) == resultArr);
//	}
//}