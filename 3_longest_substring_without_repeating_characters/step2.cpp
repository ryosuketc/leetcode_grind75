#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int max_substring_length = 0;
        std::unordered_map<char, int> seen_index;
        while (right < s.size()) {
            if (seen_index.contains(s[right])) {
                left = std::max(left, seen_index[s[right]] + 1);
            }
            max_substring_length = std::max(max_substring_length, right - left + 1);
            seen_index[s[right]] = right;
            ++right;
        }
        return max_substring_length;
    }
};
