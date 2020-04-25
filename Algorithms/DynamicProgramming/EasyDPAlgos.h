//
// Created by Mark Barbaric on 16/10/2019.
//

#ifndef GREEDY_FINALSCOREALGO_H
#define GREEDY_FINALSCOREALGO_H

#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int fibonacci(int n)
{
    if(n <= 1)
        return n;

    auto fminus1 = 0, fminus2 = 1;

    for(int i = 2; i <= n; ++i)
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

    if(n <= 1)
        return n;

    auto fminus1 = t1, fminus2 = t2;

    for(int i = 2; i <= n; ++i)
    {
        auto f = (fminus1 * fminus1) + (fminus2);
        fminus2 = fminus1;
        fminus1 = f;
    }

    return fminus1;

}


int computeDistancecBetweenPrefixes(const string& a, int aIdx, const string& b, int bIdx, vector<vector<int>>& distanceMatrix)
{
    if(aIdx < 0)
        return bIdx + 1;

    else if(bIdx < 0)
        return aIdx + 1;

    if(distanceMatrix[aIdx][bIdx] == -1)
    {
        if(a[aIdx] == b[bIdx])
        {
            distanceMatrix[aIdx][bIdx] = computeDistancecBetweenPrefixes(a, aIdx - 1, b, bIdx - 1, distanceMatrix);
        }
        else
        {
            int substitute = computeDistancecBetweenPrefixes(a, aIdx - 1, b, bIdx - 1, distanceMatrix);
            int add = computeDistancecBetweenPrefixes(a, aIdx - 1, b, bIdx, distanceMatrix);
            int del = computeDistancecBetweenPrefixes(a, aIdx, b, bIdx - 1, distanceMatrix);
            distanceMatrix[aIdx][bIdx] = 1 + min ({substitute, add, del});
        }
    }

    return distanceMatrix[aIdx][bIdx];
}

bool modifiedComputeDistance(string a, int aIdx, string b, int bIdx, vector<vector<bool>>& distanceMatrix)
{
    if(aIdx < 0)
        return bIdx + 1;
    else if(bIdx < 0)
        return aIdx + 1;

    if(distanceMatrix[aIdx][bIdx] == -1)
    {
        if(a[aIdx] == b[bIdx] || a[aIdx] == tolower(b[bIdx]))
        {
            distanceMatrix[aIdx][bIdx] = modifiedComputeDistance(a, aIdx - 1, b, bIdx - 1, distanceMatrix);
        }

        else
        {
            if(islower(a[aIdx]))
            {
                auto del = modifiedComputeDistance(a, aIdx, b, bIdx - 1, distanceMatrix);
                distanceMatrix[aIdx][bIdx] = 1 + del;
            }
        }
    }

    return distanceMatrix[aIdx][bIdx];
}

int leveshteinDistance(const string& a, const string& b)
{
    vector<vector<int>> distanceMatrix (a.length(), vector<int> (b.length(), -1)) ;
    return computeDistancecBetweenPrefixes(a, a.length() - 1, b, b.length() - 1, distanceMatrix);
}

int modifiedLeveshteinDistance(const string& a, const string& b)
{
    vector<vector<bool>> distanceMatrix (a.length(), vector<bool> (b.length(), false)) ;
    return modifiedComputeDistance(a, a.length() - 1, b, b.length() - 1, distanceMatrix);
}

int maxAdjacentSum(vector<int>& arr)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;

    for(int i = 1; i < arr.size(); ++i)
    {
        excl_new = incl > excl ? incl : excl;
        incl = excl + arr[i];
        excl = excl_new;
    }

    return (incl > excl ? incl : excl);
}



#endif //GREEDY_FINALSCOREALGO_H
