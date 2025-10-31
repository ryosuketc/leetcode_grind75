#include <algorithm>
#include <string>

class Solution {
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
            if (j >= 0 && b[j] == '1') {
                ++carry;
            }
            if (carry % 2) {
                result.push_back('1');
            } else {
                result.push_back('0');
            }
            carry /= 2;
            --j;
        }
        if (carry == 1) {
            result.push_back('1');
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
