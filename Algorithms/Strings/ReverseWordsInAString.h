#pragma once
#include "../../include/Header.h"
#include "../../Profiling/ScopedTimer.h"

namespace Algorithms::StringAlgorithms{

    std::string reverseWordsTraverse(std::string s) {
        MEASURE_FUNCTION();
        int i = 0, l = 0, r = 0;

        while(i < s.length()){
            l = i, r = l;

            while(i < s.length() - 1 && s[i] != ' '){
                i++;
            }

            r = i == s.length() - 1 ? i : i - 1;

            while(l < r){
                std::swap(s[l++], s[r--]);
            }

            i++;
        }

        return s;
    }

    void reverseString(std::string& s, int l, int r)
    {
        while(l < r)
        {
            const auto temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    }


    std::string reverseWordsStringStream(std::string s) {
        MEASURE_FUNCTION();
        std::stringstream ss (s);
        std::string token = "";
        std::string ans = "";
        auto l = 0;

        while(std::getline(ss, token, ' '))
        {
            reverseString(s, l, l + token.length() - 1);
            l += token.length() + 1;
        }


        return s;

    }


}