// Response to
// https://github.com/ryosuketc/leetcode_grind75/pull/26/files#r2543575724

// 最初こんな感じで書いてみようとしてだめでした。手でやるのをイメージして書いていたんですが、それだと結局 merge が完了しているのかどうかのフラグを脳内に持っている感じがあり、それが必要なのかなという気がします。ただいずれにせよ条件判定が複雑になるような気がしました。

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> merged_intervals;
        for (auto& interval : intervals) {
            if (!Overlap(interval, newInterval)) {
                merged_intervals.push_back(interval);
                continue;
            }
            // where to insert newInterval?
            // merge_done みたいなフラグをもつ必要がある気がする (手でやるならそうしそうな気がする)。
            // back returns a reference.
            std::vector<int>& last_interval = merged_intervals.back();
            last_interval = Merge(last_interval, interval);
        }
        return merged_intervals;
    }
private:
    bool Overlap(const std::vector<int>& interval1, const std::vector<int>& interval2) {
        // Get overlapped interval (not merged, but overlaped part).
        int overlap_start = std::max(interval1[0], interval2[0]);
        int overlap_end = std::min(interval1[1], interval2[1]);
        return overlap_start <= overlap_end;
        // 2 interval を始点でソートして比べたほうがわかりやすい気はする
    }
    std::vector<int> Merge(const std::vector<int>& interval1, const std::vector<int>& interval2) {
        int merged_start = std::min(interval1[0], interval2[0]);
        int merged_end = std::max(interval1[1], interval2[1]);
        return {merged_start, merged_end};
        }
};

// フラグがややこしいのかなと思って、1 回だけ入るループのような想定で書いてみました。
// 116 / 158 testcases passed ではありますが、`[]` に `[5,7]` を挿入するなどのケースで落ちますね。
// もし newInterval がどの区間とも重ならず、かつ既存の区間の間や先頭にある場合、newInterval はどこにも追加されずに処理が終わってしまうんですね。現在のロジックでは、!Overlap（重なりなし）の場合、intervals[i] を push_back するだけなので。

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> merged_intervals;
        int i = 0;
        while (i < intervals.size()) {
            if (!Overlap(intervals[i], newInterval)) {
                merged_intervals.push_back(intervals[i]);
                ++i;
                continue;
            }
            if (Overlap(intervals[i], newInterval)) {
                std::vector<int> merged_interval = Merge(intervals[i], newInterval);
                ++i;
                while (i < intervals.size() && Overlap(intervals[i], merged_interval)) {
                    merged_interval = Merge(intervals[i], merged_interval);
                    ++i;
                }
                merged_intervals.push_back(merged_interval);
            }
        }
        return merged_intervals;
    }
private:
    bool Overlap(const std::vector<int>& interval1, const std::vector<int>& interval2) {
        // Get overlapped interval (not merged, but overlaped part).
        int overlap_start = std::max(interval1[0], interval2[0]);
        int overlap_end = std::min(interval1[1], interval2[1]);
        return overlap_start <= overlap_end;
        // 2 interval を始点でソートして比べたほうがわかりやすい気はする
    }
    std::vector<int> Merge(const std::vector<int>& interval1, const std::vector<int>& interval2) {
        int merged_start = std::min(interval1[0], interval2[0]);
        int merged_end = std::max(interval1[1], interval2[1]);
        return {merged_start, merged_end};
        }
};

// 最終的に Gemini に直してもらったらこうなりましたが、結局 3 パターンに分類しており、3 つループを書いたほうがわかりやすいですね。

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> merged_intervals;
        int i = 0;
        bool inserted = false; // newInterval を挿入したかどうかのフラグ

        while (i < intervals.size()) {
            // ケース1: intervals[i] が newInterval より完全に「右」にある
            // -> 先に newInterval を入れる必要がある
            if (intervals[i][0] > newInterval[1]) {
                if (!inserted) {
                    merged_intervals.push_back(newInterval);
                    inserted = true;
                }
                merged_intervals.push_back(intervals[i]);
                i++;
            }
            // ケース2: intervals[i] が newInterval より完全に「左」にある
            // -> intervals[i] をそのまま入れる
            else if (intervals[i][1] < newInterval[0]) {
                merged_intervals.push_back(intervals[i]);
                i++;
            }
            // ケース3: 重なっている (Overlap)
            // -> マージして newInterval を更新し続ける（まだ push しない）
            else {
                newInterval = Merge(intervals[i], newInterval);
                i++;
            }
        }

        // ループ終了後、まだ newInterval が入っていなければ最後に追加
        if (!inserted) {
            merged_intervals.push_back(newInterval);
        }

        return merged_intervals;
    }

private:
    // Merge関数はそのまま利用可能
    std::vector<int> Merge(const std::vector<int>& interval1, const std::vector<int>& interval2) {
        int merged_start = std::min(interval1[0], interval2[0]);
        int merged_end = std::max(interval1[1], interval2[1]);
        return {merged_start, merged_end};
    }
};
