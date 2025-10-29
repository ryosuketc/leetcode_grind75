#include <unordered_map>

class Solution1 {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> char_to_frequency;
        bool has_odd_frequency = false;
        int palindrome_length = 0;
        for (char c : s) {
            ++char_to_frequency[c];
        }
        for (const auto& [c, frequency] : char_to_frequency) {
            palindrome_length += frequency;
            if (frequency % 2 == 1) {
                has_odd_frequency = true;
                // if odd, we should not add all frequency.
                palindrome_length -= 1;
            }
        }
        if (has_odd_frequency) {
            // Can add one char in the center.
            return palindrome_length + 1;
        }
        return palindrome_length;
    }
};


#include <unordered_map>

class Solution2 {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> char_to_frequency;
        bool has_odd_frequency = false;
        int palindrome_length = 0;
        for (char c : s) {
            ++char_to_frequency[c];
        }
        for (const auto& [c, frequency] : char_to_frequency) {
            if (frequency % 2 == 0) {
                palindrome_length += frequency;
                continue;
            }
            has_odd_frequency = true;
            palindrome_length += frequency - 1;
        }
        if (has_odd_frequency) {
            // Can add one char in the center.
            return palindrome_length + 1;
        }
        return palindrome_length;
    }
};
