#include <queue>

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> distances(rows, vector<int>(cols, 0));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        std::queue<vector<int>> cells_and_distances;
        // Add zeros to the queue.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                distances[row][col] = 0;
                if (mat[row][col] == 0) {
                    cells_and_distances.push({row, col, 0});
                    visited[row][col] = true;
                }
            }
        }

        // BFS traversal
        while (!cells_and_distances.empty()) {
            vector<int> info = cells_and_distances.front();
            cells_and_distances.pop();
            int row = info[0];
            int col = info[1];
            int distance = info[2];
            for (vector<int>& direction : directions) {
                int next_row = row + direction[0];
                int next_col = col + direction[1];
                if (!IsValid(next_row, next_col, rows, cols) || visited[next_row][next_col]) {
                    continue;
                }
                distances[next_row][next_col] = distance + 1;
                visited[next_row][next_col] = true;
                cells_and_distances.push({next_row, next_col, distance + 1});
            }
        }

        return distances;
    }
private:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool IsValid(int row, int col, int rows, int cols) {
        return 0 <= row && row < rows && 0 <= col && col < cols;
    }
};
