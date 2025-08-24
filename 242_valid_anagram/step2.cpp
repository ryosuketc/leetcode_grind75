// pair をそのまま使う
#include <map>

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::map<char, int> s_char_to_count = getCountMap(s);
        std::map<char, int> t_char_to_count = getCountMap(t);
        for (const auto& pair : s_char_to_count) {
            if (pair.second != t_char_to_count[pair.first]) {
                return false;
            }
        }
        return true;
    }

private:
    std::map<char, int> getCountMap(std::string s) {
        std::map<char, int> char_to_count;
        for (char c : s) {
            ++char_to_count[c];
        }
        return char_to_count;
    }

};



// find を使う
#include <map>

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::map<char, int> s_char_to_count = getCountMap(s);
        std::map<char, int> t_char_to_count = getCountMap(t);
        for (const auto& [s_char, s_count] : s_char_to_count) {
            auto it = t_char_to_count.find(s_char);
            if (it == t_char_to_count.end() || s_count != it->second) {
                return false;
            }
        }
        return true;
    }

private:
    std::map<char, int> getCountMap(std::string s) {
        std::map<char, int> char_to_count;
        for (char c : s) {
            ++char_to_count[c];
        }
        return char_to_count;
    }

};


// getCountMap に書き込み先を渡す
#include <map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::map<char, int> s_char_to_count;
        getCountMap(s, &s_char_to_count);
        std::map<char, int> t_char_to_count;
        getCountMap(t, &t_char_to_count);
        for (const auto& [s_char, s_count] : s_char_to_count) {
            auto it = t_char_to_count.find(s_char);
            if (it == t_char_to_count.end() || s_count != it->second) {
                return false;
            }
        }
        return true;
    }

private:
    void getCountMap(std::string& s, std::map<char, int>* to_map) {
        for (char c : s) {
            ++(*to_map)[c];
        }
    }

};
