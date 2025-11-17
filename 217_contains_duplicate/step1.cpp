class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen_values;
        for (auto num : nums) {
            if (seen_values.contains(num)) {
                return true;
            }
            seen_values.emplace(num);
        }
        return false;
    }
};
