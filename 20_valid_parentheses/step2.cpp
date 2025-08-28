class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> open_to_close = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        stack<int> unmatched_open_brackets;
        for (char c : s) {
            if (open_to_close.contains(c)) {
                unmatched_open_brackets.push(c);
                continue;
            }
            if (unmatched_open_brackets.empty()) {
                return false;
            }
            char expected = open_to_close.at(unmatched_open_brackets.top());
            if (expected != c) {
                return false;
            }
            unmatched_open_brackets.pop();
        }
        return unmatched_open_brackets.empty();
    }
};
