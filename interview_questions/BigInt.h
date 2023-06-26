#include <string_view>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

class BigInt {
    
    private:
    unsigned int m_size;
    std::string m_digits;

    BigInt calculate_new_int(const BigInt& lhs, const BigInt& rhs){
        
        std::string ans(lhs.size() + rhs.size(), '0');
        const auto leftNum = lhs.to_string();
        const auto rightNum = rhs.to_string();
        int l = lhs.size() - 1, r = rhs.size() - 1, index = (lhs.size() + rhs.size() - 1);
        auto remainder = 0;

        while(l >= 0 || r >= 0){
            const int leftDigit = l >= 0 ? static_cast<int>(leftNum[l] - '0') : 0;
            const int rightDigit = r >= 0 ? static_cast<int>(rightNum[r] - '0') : 0;

            auto newDigit = leftDigit + rightDigit + remainder;

            if(newDigit > 9){
                remainder = newDigit / 10;
                newDigit %= 10;
            }

            ans[index] = static_cast<char>(newDigit + '0');

            l--;
            r--;
            index--;
        }

        if(remainder) {
            ans[index] = static_cast<char>(remainder + '0');
            index--;
        }

        BigInt new_big_int(ans.substr(index + 1, ans.size()));
        return new_big_int;
    }
    
    public:

    BigInt(std::string_view rawDigits):m_digits(rawDigits)
    {
    }

    std::string_view to_string() const noexcept { 
        return m_digits;
    }

    BigInt operator +(BigInt& rhs){
        return calculate_new_int(*this, rhs);
    }

    size_t size() const noexcept { return m_digits.length();}
};