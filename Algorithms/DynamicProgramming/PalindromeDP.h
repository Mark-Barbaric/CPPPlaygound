#pragma once
#include <string>

namespace PalindromeDP
{

	inline bool IsPalindrome(std::string& word)
	{
		if (word.length() == 0)
			return false;
		
		auto l = 0;
		auto r = word.length() - 1;

		while(l < r)
		{
			if (word[l++] != word[r--])
				return false;
		}

		return true;
	}
	
	inline int LongestPalindromeBF(std::string& word)
	{
		auto count = 0;
		
		for(int i = 0; i < word.size(); ++i)
		{
			for(int j = 0; j <= word.size() - i; ++j)
			{
				auto sub = word.substr(i, j);

				if(IsPalindrome(sub) && sub.length() > count)
				{
					count = sub.length();
				}
			}
		}
		return count;
	} 
	inline int LongestPalindromeDP(std::string& word)
	{
		if (word.length() == 0 || word.length() == 1)
			return word.length();

		auto start = 0, end = 0;
		std::string res = "";

		std::vector<std::vector<bool>> stringMatrix(word.size(), std::vector<bool>(word.size(), 0));

		//1 length strings
		for (int i = 0; i < word.size(); ++i)
			stringMatrix[i][i] = true;

		//2 length strings
		for(int i = 0; i < word.size() - 1; ++i)
		{
			if(word[i] == word[i + 1])
			{
				stringMatrix[i][i + 1] = true;
				start = i;
				end = i + 1;
			}
		}
		
		for(int k = 2; k < word.size(); ++k)
		{
			for(int i = 0; i < word.size() - k; ++i)
			{
				auto j = i + k;

				if(word[i] == word[j] && stringMatrix[i + 1][j-1])
				{
					start = i;
					end = j;
					stringMatrix[i][j] = true;
				}
			}
		}

		res = word.substr(start, end - start + 1);
		return res.length();
	}
}