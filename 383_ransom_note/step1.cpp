class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::map<char> char_count;
        for (char c : magazine) {
            ++char_count[c];
        }
        for (char c : ransomNote) {
            if (!char_count.contains(c) || char_count[c] == 0) {
                return false;
            }
            --char_count[c];
        }
        return true;
    }
};
