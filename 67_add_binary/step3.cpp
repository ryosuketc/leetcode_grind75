

#include <algorithm>
#include <string>

class Solution {
private:
    void EqualizeLength(std::string& a, std::string& b) {
        int max_length = std::max(a.size(), b.size());
        if (a.size() < max_length) {
            a.insert(0, max_length - a.size(), '0'); 
        }
        if (b.size() < max_length) {
            b.insert(0, max_length - b.size(), '0');
        }
    }

public:
    string addBinary(string a, string b) {
        EqualizeLength(a, b);
        std::string result;
        int carry = 0;
        for (int i = a.size() - 1; i >= 0; --i) {
            int a_int = a[i] - '0';
            int b_int = b[i] - '0';
            int total = carry + a_int + b_int;

            char digit;
            if (total % 2) {
                digit = '1';
            } else {
                digit = '0';
            }
            result.push_back(digit);
            carry = total / 2;
        }
        if (carry == 1) {
            result.push_back('1');
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
