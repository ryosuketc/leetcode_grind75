#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (!std::isalnum(s[left])) {
                ++left;
                continue;
            }
            if (!std::isalnum(s[right])) {
                --right;
                continue;
            }
            char c_left = std::tolower(s[left]);
            char c_right = std::tolower(s[right]);
            if (c_left != c_right) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
