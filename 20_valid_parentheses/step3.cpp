class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> open_to_close = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        stack<char> unmatched_open_brackets;
        for (char c : s) {
            if (open_to_close.contains(c)) {
                unmatched_open_brackets.push(c);
                continue;
            }
            if (unmatched_open_brackets.empty()) {
                return false;
            }
            char expected_close = open_to_close[unmatched_open_brackets.top()];
            if (c != expected_close) {
                return false;
            }
            unmatched_open_brackets.pop();
        }
        return unmatched_open_brackets.empty();
    }
};
