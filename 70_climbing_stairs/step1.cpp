class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return n;
        }
        int ways;
        // Starting from ways(0) = 0
        int two_steps_before = 0;
        // ways(1) = 1
        int one_step_before = 1;
        // Run n times.
        for (int i = 0; i < n; ++i) {
            ways = two_steps_before + one_step_before;
            two_steps_before = one_step_before;
            one_step_before = ways;
        }
        return ways;
    }
};
