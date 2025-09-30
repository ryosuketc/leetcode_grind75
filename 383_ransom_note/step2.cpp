// WA - `erase` はそのキーの全ての要素を削除する

class Solution1WA {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::multiset<char> char_count;
        for (char c : magazine) {
            char_count.insert(c);
        }
        for (char c : ransomNote) {
            if (!char_count.contains(c)) {
                return false;
            }
            char_count.erase(c);
        }
        return true;
    }
};


class Solution1AC {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::multiset<char> char_count;
        for (char c : magazine) {
            char_count.insert(c);
        }
        for (char c : ransomNote) {
            if (!char_count.contains(c)) {
                return false;
            }
            auto it = char_count.find(c);
            if (it == char_count.end()) {
                return false; // no match found
            }
            char_count.erase(it);
        }
        return true;
    }
};

class Solution2 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::vector<int> char_count(26, 0);
        for (char c : magazine) {
            ++char_count[c - 'a'];
        }
        for (char c : ransomNote) {
            if (char_count[c - 'a'] == 0) {
                return false;
            }
            --char_count[c - 'a'];
        }
        return true;

    }
};
