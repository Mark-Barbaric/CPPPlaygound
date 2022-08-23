#pragma once
#include <iostream>
#include <vector>

namespace MediumDP
{
    inline int numUniqueCombinationsTabulated(const int finalScore, std::vector<int> scores)
    {
         std::vector<int> dp (finalScore + 1, 0);
         dp[0] = 1;

         for (auto& s : scores) {

             for (int j = 1; j <= finalScore; ++j)
             {
             	if(j >= s)
             	{
                    dp[j] += dp[j - s];
             	}
             }
         }
        

        return dp.back();
    }

	inline int numCombinationsTabulated(const int finalScore, std::vector<int> scores)
    {
        std::vector<int> dp(finalScore + 1, 0);
        dp[0] = 1;

        for (int j = 1; j <= finalScore; ++j)
        {

            for (auto& s : scores) {
                if (j >= s)
                {
                    dp[j] += dp[j - s];
                }
            }
        }

        return dp.back();
    }

    inline int topDownHelper(const int min, const int finalScore, std::vector<int> scores, std::vector<int>& dp)
    {
        if(dp[finalScore] != -1)
        {
            return dp[finalScore];
        }

    	for(auto& s : scores)
    	{
    		if(finalScore >= s && s >= min)
    		{
                auto cur = topDownHelper(s, finalScore - s, scores, dp);
                dp[finalScore] = dp[finalScore] == -1 ? cur : dp[finalScore] + cur;
    		}
    	}

        return dp[finalScore];
    }
	
	inline int numCombinationsMemoization(const int finalScore, std::vector<int> scores)
    {
        std::vector<int> dp(finalScore + 1, -1);
        dp[0] = 1;
        topDownHelper(0, finalScore, scores, dp);
        return dp.back();
    }

    inline int topDownHelper2(const int finalScore, const int score, std::vector<int>& dp)
    {
    	if(dp[finalScore] != -1)
    	{
            return dp[finalScore];
    	}

    	if(finalScore >= score)
    	{
            auto cur = topDownHelper2(finalScore - score, score, dp);
            dp[finalScore] = dp[finalScore] == -1 ? cur : dp[finalScore] + cur;
    	}

        return dp[finalScore];
    }

	
	inline int numCombinationsUniqueMoization(const int finalScore, std::vector<int> scores)
    {
        std::vector<int> dp(finalScore + 1, -1);
        dp[0] = 1;

    	for(auto& s : scores)
    	{
            topDownHelper2(finalScore, s, dp);
    	}

        return dp.back();
    }

    inline void recursiveCombinationsSearch(const int min, const int target, std::vector<int> scores, std::vector<int> temp, std::vector<std::vector<int>>& combinationsMatrix)
    {
        if (target == 0)
            combinationsMatrix.push_back(temp);

        for (int i = 0; i < scores.size(); ++i)
        {
            if (target - scores[i] >= 0 && scores[i] >= min)
            {
                temp.push_back(scores[i]);
                recursiveCombinationsSearch(scores[i], target - scores[i], scores, temp, combinationsMatrix);
                temp.pop_back();
            }
        }
    }

    inline std::vector<std::vector<int>> numCombinationsOutcomes(const int finalScore, const std::vector<int> scores)
    {
        std::vector<std::vector<int>> scoreCombinations;
        std::vector<int> temp;
        recursiveCombinationsSearch(0, finalScore, scores, temp, scoreCombinations);
        return scoreCombinations;
    }
}
