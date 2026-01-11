// sort + hashset
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target_num =-nums[i]; // nums[i] - 0
            std::unordered_set<int> seen;
            for (int j = i + 1; j < nums.size(); ++j) {
                int complement = target_num - nums[j];
                if (seen.contains(complement)) {
                    triplets.push_back({nums[i], nums[j], complement});
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                }
                seen.insert(nums[j]);
            }
        }
        return triplets;   
    }
};

// sort + two pointers
#include <algorithm>

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            // To avoid duplicates (skip the same number)
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    ++left;
                    continue;
                }
                if (sum > 0) {
                    --right;
                    continue;
                }
                // sum == 0
                result.push_back({nums[i], nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right - 1] == nums[right]) --right;
                ++left;
                --right;
            }
        }
        return result;
    }
};
