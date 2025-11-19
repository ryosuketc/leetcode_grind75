class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> result;
        int insertion_start = newInterval[0];
        int insertion_end = newInterval[1];
        int i = 0;
        // No overlap -> push_back as is.
        while (i < intervals.size() && intervals[i][1] < insertion_start) {
            result.push_back(intervals[i++]);
        }
        // Handle overlaps
        while (i < intervals.size() && intervals[i][0] <= insertion_end) {
            insertion_start = std::min(insertion_start, intervals[i][0]);
            insertion_end = std::max(insertion_end, intervals[i][1]);
            ++i;
        }
        result.push_back({insertion_start, insertion_end});

        // The rest (if remaining)
        while (i < intervals.size()) {
            result.push_back(intervals[i++]);
        }
        return result;
    }
};
