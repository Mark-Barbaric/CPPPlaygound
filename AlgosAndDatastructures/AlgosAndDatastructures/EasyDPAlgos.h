//
// Created by Mark Barbaric on 16/10/2019.
//

#ifndef GREEDY_FINALSCOREALGO_H
#define GREEDY_FINALSCOREALGO_H

#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void search2(int n, int k, int start, int step, vector<int> temp, vector<vector<int>>& results)
{
	if (step == k)
		results.push_back(temp);

	for (int i = start; i <= n; ++i)
	{
		temp.push_back(i);
		search2(n, k, temp[temp.size() - 1] + 1, step + 1, temp, results);
		temp.pop_back();
	}
}

vector<vector<int>> combinations(int n, int k)
{
	vector<vector<int>> results;
	vector<int> temp;
	search2(n, k, 1, 0, temp, results);
	return results;
}

void search(int min, int target, vector<int> temp, vector<vector<int>>& results, const vector<int>& scores)
{
	if (target == 0)
		results.push_back(temp);

	unordered_set<int> s;

	for (int i = 0; i < scores.size(); ++i)
	{
		if (target - scores[i] >= 0 && scores[i] >= min)
		{
			temp.push_back(scores[i]);
			search(scores[i], target - scores[i], temp, results, scores);
			temp.pop_back();
		}
	}
}

vector<vector<int>> finalScoreCombinations(int target, const vector<int>& scores)
{
	vector<vector<int>> results;
	vector<int> temp;
	search(0, target, temp, results, scores);
	return results;
}


vector<vector<int>> finalScoreCombinationsNoDups(int target, const vector<int>& scores)
{
	vector<vector<int>> results;
	vector<int> temp;
	search(0, target, temp, results, scores);
	return results;
}

int fibonacci(int n)
{
	if (n <= 1)
		return n;

	auto fminus1 = 0, fminus2 = 1;

	for (int i = 2; i <= n; ++i)
	{
		auto f = fminus1 + fminus2;
		fminus2 = fminus1;
		fminus1 = f;
	}

	return fminus1;
}

unsigned long long factorial(int n)
{
	const unsigned int M = 1000000007;

	unsigned long long f = 1;
	for (int i = 1; i <= n; i++)
		f = (f*i) % M;  // Now f never can
	// exceed 10^9+7
	return f;
}

unsigned long long fibonacciModified(int t1, int t2, int n)
{

	if (n <= 1)
		return n;

	auto fminus1 = t1, fminus2 = t2;

	for (int i = 2; i <= n; ++i)
	{
		auto f = (fminus1 * fminus1) + (fminus2);
		fminus2 = fminus1;
		fminus1 = f;
	}

	return fminus1;

}


int computeDistancecBetweenPrefixes(const string& a, int aIdx, const string& b, int bIdx, vector<vector<int>>& distanceMatrix)
{
	if (aIdx < 0)
		return bIdx + 1;

	else if (bIdx < 0)
		return aIdx + 1;

	if (distanceMatrix[aIdx][bIdx] == -1)
	{
		if (a[aIdx] == b[bIdx])
		{
			distanceMatrix[aIdx][bIdx] = computeDistancecBetweenPrefixes(a, aIdx - 1, b, bIdx - 1, distanceMatrix);
		}
		else
		{
			int substitute = computeDistancecBetweenPrefixes(a, aIdx - 1, b, bIdx - 1, distanceMatrix);
			int add = computeDistancecBetweenPrefixes(a, aIdx - 1, b, bIdx, distanceMatrix);
			int del = computeDistancecBetweenPrefixes(a, aIdx, b, bIdx - 1, distanceMatrix);
			distanceMatrix[aIdx][bIdx] = 1 + min({ substitute, add, del });
		}
	}

	return distanceMatrix[aIdx][bIdx];
}

//bool modifiedComputeDistance(string a, int aIdx, string b, int bIdx, vector<vector<bool>>& distanceMatrix)
//{
//	if (aIdx < 0)
//		return bIdx + 1;
//	else if (bIdx < 0)
//		return aIdx + 1;
//
//	if (distanceMatrix[aIdx][bIdx] == -1)
//	{
//		if (a[aIdx] == b[bIdx] || a[aIdx] == tolower(b[bIdx]))
//		{
//			distanceMatrix[aIdx][bIdx] = modifiedComputeDistance(a, aIdx - 1, b, bIdx - 1, distanceMatrix);
//		}
//
//		else
//		{
//			if (islower(a[aIdx]))
//			{
//				auto del = modifiedComputeDistance(a, aIdx, b, bIdx - 1, distanceMatrix);
//				distanceMatrix[aIdx][bIdx] = 1 + del;
//			}
//		}
//	}
//
//	return distanceMatrix[aIdx][bIdx];
//}

//int leveshteinDistance(const string& a, const string& b)
//{
//	vector<vector<int>> distanceMatrix(a.length(), vector<int>(b.length(), -1));
//	return computeDistancecBetweenPrefixes(a, a.length() - 1, b, b.length() - 1, distanceMatrix);
//}
//
//int modifiedLeveshteinDistance(const string& a, const string& b)
//{
//	vector<vector<bool>> distanceMatrix(a.length(), vector<bool>(b.length(), false));
//	return modifiedComputeDistance(a, a.length() - 1, b, b.length() - 1, distanceMatrix);
//}

int maxAdjacentSum(vector<int>& arr)
{
	int incl = arr[0];
	int excl = 0;
	int excl_new;

	for (int i = 1; i < arr.size(); ++i)
	{
		excl_new = incl > excl ? incl : excl;
		incl = excl + arr[i];
		excl = excl_new;
	}

	return (incl > excl ? incl : excl);
}

int knapsackAlgo(const vector<pair<int, int>>& items, int k, int capacity, vector<vector<int>>& matrix)
{
	if (k < 0)
		return 0;
	if (matrix[k][capacity] == -1)
	{
		auto withoutCurrent = knapsackAlgo(items, k - 1, capacity, matrix);
		auto withCurrent = capacity < items[k].first ? 0 : items[k].second + knapsackAlgo(items, k - 1, capacity - items[k].first, matrix);
		matrix[k][capacity] = max(withCurrent, withoutCurrent);

	}

	return matrix[k][capacity];
}

#endif //GREEDY_FINALSCOREALGO_H
