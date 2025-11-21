class SolutionWA1 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int new_interval_start = newInterval[0];
        int new_interval_end = newInterval[1];
        std::vector<std::vector<int>> result;
        int i = 0;
        bool has_overlap = false;
        while (i < intervals.size()) {
            int interval_start = intervals[i][0]; // Fixed
            int interval_end = intervals[i][1]; // Temp. end. Not fixed yet.
            if (new_interval_start <= interval_end) {
                interval_end = std::max(interval_end, new_interval_end);
            }
            int j = i + 1;

            while (j < intervals.size() && intervals[j][0] <= interval_end) {
                interval_end = std::max(interval_end, intervals[j][1]);
                ++j;
            }
            result.push_back({interval_start, interval_end});
            i = j;
        }
        return result;
    }
};



class SolutionWA2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int new_interval_start = newInterval[0];
        int new_interval_end = newInterval[1];
        std::vector<std::vector<int>> result;
        int i = 0;
        bool has_overlap = false;
        while (i < intervals.size()) {
            int interval_start = intervals[i][0]; // Fixed
            int interval_end = intervals[i][1]; // Temp. end. Not fixed yet.
            if (new_interval_start <= interval_end) {
                has_overlap = true;
                interval_end = std::max(interval_end, new_interval_end);
            }
            int j = i + 1;

            while (j < intervals.size() && intervals[j][0] <= interval_end) {
                has_overlap = true;
                interval_end = std::max(interval_end, intervals[j][1]);
                ++j;
            }
            result.push_back({interval_start, interval_end});
            i = j;
        }
        if (!has_overlap) {
            result.push_back(newInterval);
            return result;
        }
        return result;
    }
};
