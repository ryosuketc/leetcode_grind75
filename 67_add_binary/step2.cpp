#include <algorithm>
#include <string>

class Solution1 {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            return addBinary(b, a);
        }

        std::string result;
        int carry = 0;
        int j = b.size() - 1;
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] == '1') {
                ++carry;
            }
            if (j >= 0 && b[j--] == '1') {
                ++carry;
            }
            result.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }
        if (carry == 1) {
            result.push_back('1');
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};


#include <algorithm>
#include <string>

class Solution2 {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            return addBinary(b, a);
        }

        std::string result;
        int carry = 0;
        int j = b.size() - 1;
        for (int i = a.size() - 1; i >= 0; --i) {
            int total = carry;
            if (a[i] == '1') {
                ++total;
            }
            if (j >= 0 && b[j] == '1') {
                ++total;
            }
            --j;

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
