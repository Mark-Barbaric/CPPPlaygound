#ifndef HASH_SET_H
#define HASH_SET_H

#include "../Trees/BinarySearchTree.h"
#include "../../Header.h"

template <typename T>
class Bucket
{
	std::unique_ptr<BinarySearchTree<T>> bst;
	
public:
	Bucket()
	{
		bst = std::make_unique<BinarySearchTree<T>*>(new BinarySearchTree<T>);
	}

	void insert(T t)
	{
		bst->insertNode(t);
	}

	void remove(T t)
	{
		bst->deleteNode(t);
	}

	bool find(T t)
	{
		return bst->findNode(t) != nullptr;
	}
};


template <typename T>
class HashSet
{
	Bucket<T> buckets [769];

	int hash(int key) const noexcept { return key % hash; }

public:

	HashSet() = default;

	void add(T key)
	{
		const auto bucketIndex = hash(key);
		buckets[bucketIndex].insert(key);
	}

	void remove(T key)
	{
		const auto bucketIndex = hash(key);
		buckets[bucketIndex].remove(key);
	}

	bool contains(T key)
	{
		const auto bucketIndex = hash(key);
		return buckets[bucketIndex].find(key);
	}
	
	
};


#endif
