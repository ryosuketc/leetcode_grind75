#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        std::unordered_set<char> chars_in_substring;
        int max_substring_length = 0;
        for (int right = 0; right < s.size(); ++right) {
            while (chars_in_substring.contains(s[right])) {
                chars_in_substring.erase(s[left]);
                ++left;
            }
            chars_in_substring.insert(s[right]);
            max_substring_length = std::max(max_substring_length, right - left + 1);
        }
        return max_substring_length;
    }
};
