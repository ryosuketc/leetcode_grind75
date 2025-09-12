// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (!isBadVersion(mid)) {
                // Search right
                left = mid + 1;
                continue;
            }
            // mid is bad version
            if (mid > 1 && isBadVersion(mid - 1)) {
                // Search left
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return 0; // no bad version
    }
};
