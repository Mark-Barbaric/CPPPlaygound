#ifndef MEDIAN_HEAP_H
#define MEDIAN_HEAP_H

#include "../../Header.h"

template <typename Type>

class MedianHeap
{
	std::priority_queue<Type, std::vector<Type>, std::greater<Type>> maxQ;
	std::priority_queue<Type> minQ;

public:

	MedianHeap() = default;

	void insert(Type val)
	{
		minQ.push(val);
		maxQ.push(minQ.top());
		minQ.pop();

		if(minQ.size() < maxQ.size())
		{
			minQ.push(maxQ.top());
			maxQ.pop();
		}
		
	}

	Type getMedian() const
	{
		if(minQ.size() > maxQ.size())
		{
			return minQ.top();
		} else
		{
			return static_cast<double>(maxQ.top()) + static_cast<double>(minQ.top()) / 2.0;
		}
	}
};




#endif