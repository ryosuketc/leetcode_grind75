class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0; // error
        }
        int max_subarray_sum = 0;
        int subarray_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (subarray_sum < num) {
                subarray_sum = num; // Reset the window
                max_subarray_sum = std::max(max_subarray_sum, subarray_sum);
                continue;
            }
            subarray_sum += num;
            max_subarray_sum = std::max(max_subarray_sum, subarray_sum);
        }
        return max_subarray_sum;

    }
};


class SolutionAC {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0; // error
        }
        int max_subarray_sum = nums[0];
        int subarray_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (subarray_sum < 0 && subarray_sum < num) {
                subarray_sum = num; // Reset the window
                max_subarray_sum = std::max(max_subarray_sum, subarray_sum);
                continue;
            }
            subarray_sum += num;
            max_subarray_sum = std::max(max_subarray_sum, subarray_sum);
        }
        return max_subarray_sum;

    }
};
