#include <map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::map<char, int> s_char_to_count = getCountMap(s);
        std::map<char, int> t_char_to_count = getCountMap(t);
        for (const auto& [s_char, s_char_count] : s_char_to_count) {
            if (s_char_count != t_char_to_count[s_char]) {
                return false;
            }
        }
        return true;
    }

private:
    std::map<char, int> getCountMap(const std::string& s) {
        std::map<char, int> char_to_count;
        for (char c : s) {
            ++char_to_count[c];
        }
        return char_to_count;
    }

};
