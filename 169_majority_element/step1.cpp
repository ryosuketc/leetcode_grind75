#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> num_to_count;
        for (int num : nums) {
            ++num_to_count[num];
        }
        for (auto& [num, count] : num_to_count) {
            if (count > nums.size() / 2) {
                return num;
            }
        }
        // Guaranteed that nums have the majority element.
        std::unreachable();
    }
};
