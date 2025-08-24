#include <set>
#include <stack>
#include <utility>

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color = image[sr][sc];
        int num_rows = image.size();
        int num_cols = image[0].size();
        std::set<std::pair<int, int>> visited;
        std::stack<std::pair<int, int>> pixels;
        pixels.push(std::make_pair(sr, sc));
        while (!pixels.empty()) {
            std::pair<int, int> position = pixels.top();
            auto [x, y] = position;
            pixels.pop();
            if (!(0 <= x && x < num_rows && 0 <= y && y < num_cols)) {
                continue;
            }
            if (visited.contains(position)) {
                continue;
            }
            visited.insert(position);
            if (image[x][y] != original_color) {
                continue;
            }
            image[x][y] = color;
            pixels.push(std::make_pair(x + 1, y));
            pixels.push(std::make_pair(x - 1, y));
            pixels.push(std::make_pair(x, y + 1));
            pixels.push(std::make_pair(x , y - 1));
        }
        return image;
    }
};
