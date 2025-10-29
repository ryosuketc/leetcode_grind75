// Solving wrong question (書きかけで放置).
class Solution {
private:
    int longestPalindromeStartingAt(string s, int start_index) {
        string longest_palindrome;
        int left = start_index;
        int right = start_index;
        while (left >= 0 && right < s.length) {
            if s[left] != s[right] {
                break;
            }
            longest_palindrome = s[left: right + 1]
            --left;
            ++right;
        }
        return 
    }
public:
    int longestPalindrome(string s) {
        string longest_palindrome;
        for (i = 0; i < s.length; ++i) {
        }
        
    }
};

// Correct solution
#include <unordered_map>

class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> char_to_frequency;
        bool has_odd_frequency = false;
        int palindrome_length = 0;
        for (char c : s) {
            ++char_to_frequency[c];
        }
        for (const auto& [c, frequency] : char_to_frequency) {
            if (frequency % 2 == 1) {
                has_odd_frequency = true;
                palindrome_length += frequency - 1;
            } else {
                palindrome_length += frequency;
            }
        }
        if (has_odd_frequency) {
            // Can add one char in the center.
            return palindrome_length + 1;
        }
        return palindrome_length;
    }
};
