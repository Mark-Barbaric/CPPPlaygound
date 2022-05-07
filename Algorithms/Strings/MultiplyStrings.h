#include <string>

namespace StringAlgorithms{

    inline std::string multiplyStrings(std::string num1, std::string num2) {

        if(num1 == "0" || num2 == "0"){
            return "0";
        }

        const auto smallestString = num1.length() <= num2.length() ? num1 : num2;
        const auto largestString = num1.length() > num2.length() ? num1 : num2;
        int remainder = 0;
        std::string ans (largestString.length(), '0');
        int count = 1, r = ans.length() - count, l = r;

        for(auto c1 = smallestString.rbegin(); c1 != smallestString.rend(); ++c1){

            for(auto c2 = largestString.rbegin(); c2 != largestString.rend(); ++c2){

                auto mult = ((*c1 - '0') * (*c2 - '0')) + remainder;
                remainder = mult / 10;
                mult %= 10;

                if(l < 0){
                    ans = static_cast<char>(mult + '0') + ans;
                } else {
                    auto newMult = (ans[l] - '0') + mult;
                    remainder += newMult / 10;
                    newMult %= 10;
                    ans[l--] = static_cast<char>(newMult + '0');
                }
            }

            if(remainder){
                ans = static_cast<char>(remainder + '0') + ans;
                remainder = 0;
            }

            count++;
            r = ans.length() - count;
            l = r;
        }

        return ans;
    }


}