#include <set>
#include <utility>

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color = image[sr][sc];
        std::set<std::pair<int, int>> visited;
        floodFillHelper(image, sr, sc, original_color, color, visited);
        return image;
    }
private:
    void floodFillHelper(vector<vector<int>>& image, int x, int y, int original_color, int color, std::set<std::pair<int, int>>& visited) {
        int num_rows = image.size();
        int num_cols = image[0].size();
        if (!(0 <= x && x < num_rows && 0 <= y && y < num_cols)) {
            return;
        }
        auto position = std::make_pair(x, y);
        if (visited.contains(position)) {
            return;
        }
        visited.insert(position);
        if (image[x][y] != original_color) {
            return;
        }
        image[x][y] = color;
        floodFillHelper(image, x + 1, y, original_color, color, visited);
        floodFillHelper(image, x - 1, y, original_color, color, visited);
        floodFillHelper(image, x, y + 1, original_color, color, visited);
        floodFillHelper(image, x, y - 1, original_color, color, visited);
    }
};
