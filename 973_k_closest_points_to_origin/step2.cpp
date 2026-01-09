// heap
#include <queue>

class Solution1 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // (distance, point pair)
        std::priority_queue<std::pair<int, vector<int>>> k_closest_points;
        for (auto point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            k_closest_points.push(std::make_pair(distance, point));
            if (k_closest_points.size() > k) {
                k_closest_points.pop();
            }
        }

        std::vector<std::vector<int>> result;
        while (!k_closest_points.empty()) {
            auto p = k_closest_points.top();
            result.push_back(p.second);
            k_closest_points.pop();
        }
        return result;
    }
};


// sort (lambda)
#include <algorithm>

class Solution2_1 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // note: the arg (point) is edited, you may want to copy
        // std::vector<std::vector<int>> points_copy = points;
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b){
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        });
        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
    }
};


// sort (private function)
#include <algorithm>

class Solution2_2 {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        // note: the arg (point) is edited, you may want to copy
        // std::vector<std::vector<int>> points_copy = points;
        std::sort(points.begin(), points.end(), isCloser);
        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
    }

private:
    static bool isCloser(const std::vector<int>& a, const std::vector<int>& b){
        long distance_a = a[0] * a[0] + a[1] * a[1];
        long distance_b = b[0] * b[0] + b[1] * b[1];
        return distance_a < distance_b;
    }
};


// struct
#include <algorithm>

struct Point {
    int x, y;
    int sq_distance;

    Point(const std::vector<int>& p) : x(p[0]), y(p[1]) {
        sq_distance = x * x + y * y;
    }

    // Operator overload for std::sort (`<` is used by default)
    bool operator<(const Point& other) const {
        return sq_distance < other.sq_distance;
    }

    std::vector<int> toVector() const {
        return {x, y};
    }
};

class Solution3 {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::vector<Point> wrapped_points;
        for (const auto& p : points) {
            wrapped_points.push_back(p);
        }

        std::sort(wrapped_points.begin(), wrapped_points.end());

        std::vector<std::vector<int>> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(wrapped_points[i].toVector());
        }
        return result;
    }
};


// quick select
#include <algorithm>

class Solution4 {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::nth_element(points.begin(), points.begin() + k, points.end(), 
            [](const std::vector<int>& a, const std::vector<int>& b) {
                return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
            });
        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
    }
};
