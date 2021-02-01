#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
struct ListNode
{
	ListNode<T>* next = nullptr;
	int val = 0;

	ListNode() = default;
	ListNode(const int v):val(v){}
	ListNode(const int v, ListNode<T>* n):val(v),next(n){}
};

template<typename T>
class LinkedList
{
	ListNode<T>* head = nullptr;

	ListNode<T>* insertNodeUtil(ListNode<T>* head, T val)
	{
		if (!head)
		{
			return new ListNode<T>(val);
		}

		auto* dummy = head;

		while (dummy && dummy->next)
		{
			dummy = dummy->next;
		}

		dummy->next = new ListNode<T>(val);

		return head;
	}

	ListNode<T>* deleteNodeUtil(ListNode<T>* head, T val)
	{
		if(head->val == val)
		{
			head = head->next;
			return head;
		}

		ListNode<T>* dummy = head, *prev = nullptr;

		while(dummy)
		{

			if(dummy->val == val)
			{
				prev->next = dummy->next;
				break;
			}
			
			prev = dummy;
			dummy = dummy->next;
		}
		
		return head;
	}

	std::string traverseNodesUtil() const
	{
		std::string ans = "";
		auto* dummy = head;
		
		while(dummy)
		{
			if(!ans.empty())
			{
				ans += ' ';
			}

			ans += std::to_string(dummy->val);
			dummy = dummy->next;
		}

		return ans;
	}

	bool containsNodeUtil(ListNode<T>* head, T val) const
	{
		auto* dummy = head;

		while(dummy)
		{
			if (val == dummy->val)
				return true;
			
			dummy = dummy->next;
		}

		return false;
	}

public:

	LinkedList() = default;

	void insertNode(T val)
	{
		head = insertNodeUtil(head, val);
	}

	void deleteNode(T val)
	{
		head = deleteNodeUtil(head, val);
	}

	bool containsNode(T val)
	{
		return containsNodeUtil(head, val);
	}

	std::string traverseNodes() const { return traverseNodesUtil(); }

	ListNode<T>* getHeadNode() { return head; }
};





#endif