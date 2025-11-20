#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        // if (rows == 0) return mat;
        int cols = mat[0].size();
        // Use a safe "infinity" that won't overflow when adding 1
        int INF = numeric_limits<int>::max() - 10000;
        // Initialization: Set non-zero cells to inf.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] != 0) {
                    mat[row][col] = INF;
                }
            }
        }

        // First pass: Check top and left neighbors
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 0) {
                    continue;
                }
                
                if (row > 0) {
                    // top (up)
                    mat[row][col] = min(mat[row][col], mat[row - 1][col] + 1);
                }
                if (col > 0) {
                    // left
                    mat[row][col] = min(mat[row][col], mat[row][col - 1] + 1);
                }
            }
        }

        // Second pass: Check bottom and right neighbors (iterate backwards)
        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                if (mat[row][col] == 0) {
                    continue;
                }
                
                if (row < rows - 1) {
                    // bottom (down)
                    mat[row][col] = min(mat[row][col], mat[row + 1][col] + 1);
                }
                if (col < cols - 1) {
                    // right
                    mat[row][col] = min(mat[row][col], mat[row][col + 1] + 1);
                }
            }
        }
        return mat;
    }
};
