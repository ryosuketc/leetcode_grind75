class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0; // error
        }
        int max_subarray_sum = nums[0];
        int subarray_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            subarray_sum = std::max(num, subarray_sum + num);
            max_subarray_sum = std::max(max_subarray_sum, subarray_sum);
        }
        return max_subarray_sum;

    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0; // error
        }
        int max_subarray_sum = std::numeric_limits<int>::min();
        int subarray_sum = 0;
        for (auto num : nums) {
            subarray_sum = std::max(num, subarray_sum + num);
            max_subarray_sum = std::max(max_subarray_sum, subarray_sum);
        }
        return max_subarray_sum;

    }
};
