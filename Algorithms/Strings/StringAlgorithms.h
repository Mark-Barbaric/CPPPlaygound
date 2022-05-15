#ifndef STRING_ALGORITHMS_H
#define STRING_ALGORITMS_H

#include "include/Header.h"

namespace StringAlgorithms
{
    inline std::string fixedString(std::string& str)
    {
        std::stack<char> st;
        std::string ans = "";
        int l = 0, r = str.length();

        for (auto& c : str)
        {
            ans += c;
            if (c == '<')
            {
                st.push(c);
                r++;
            }

            if (c == '>' && !st.empty())
            {
                if (st.top() == '<')
                {
                    st.pop();
                    r--;
                }


            }
            else if (c == '>' && st.empty())
            {
                ans.insert(l, 1, '<');
                l++;
            }
        }

        if (!st.empty())
        {
            for (int i = str.length(); i < r; ++i)
            {
                ans.insert(i, 1, '>');
            }
        }

        return ans;

    }

    inline int optimisedMaximumSubstring(std::string s)
    {
        auto n = s.length();
        auto i = 0, j = 0;
        std::unordered_set<char> set;
        auto count = 0;

        while (i < n && j < n)
        {
            if (set.count(s[i]) == 0)
            {
                set.insert(s[i++]);
                count = std::max(count, i - j);
            }
            else
                set.erase(s[j++]);

        }

        return count;
    }

	inline bool IsAnagram(std::string s1, std::string s2)
    {
        if (s1.length() != s2.length())
            return false;

        std::vector<int> arr(26, 0);

        for(int i = 0; i < s1.length(); ++i)
        {
            auto index1 = s1.at(i) - 'a';
            auto index2 = s2.at(i) - 'a';
            arr[index1]++;
            arr[index2]--;
        }

        for (int c : arr)
            if (c != 0)
                return false;

        return true;   	
    }

	inline int FirstUniqueChar(std::string s)
    {
        if (s.length() == 0)
            return -1;

        std::vector<int> count(26, 0);

    	for(int i = 0; i < s.length(); ++i)
    	{
            count[s.at(i) - 'a']++;
    	}

        for (int i = 0; i < s.length(); ++i)
        {
            if (count[s.at(i) - 'a'] == 1)
                return i;
        }

 
        return -1;
    }
}




#endif