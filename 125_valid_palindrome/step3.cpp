class Solution {
private:
    std::string to_lower_alnum(std::string s) {
        std::string lower_alnum_string;
        for (char c : s) {
            if (std::isalnum(c)) {
                lower_alnum_string.push_back(std::tolower(c));
            }
        }
        return lower_alnum_string;
    }

public:
    bool isPalindrome(string s) {
        std::string lower_alnum_string = to_lower_alnum(s);
        int left = 0;
        int right = lower_alnum_string.size() - 1;
        while (left < right) {
            if (lower_alnum_string[left] != lower_alnum_string[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
