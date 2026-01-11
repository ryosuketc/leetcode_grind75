class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        for (int i = 0; i < nums.size(); ++i) {
            int target_num = -nums[i]; // nums[i] - 0
            std::unordered_set<int> seen;
            for (int j = i + 1; j < nums.size(); ++j) {
                int complement = target_num - nums[j];
                if (seen.contains(complement)) {
                    triplets.push_back({nums[i], nums[j], complement});
                }
                seen.insert(nums[j]);
            }
        }
        return triplets;   
    }
};
