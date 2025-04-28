#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> next(cols, vector<int>(cols, 0));
        vector<vector<int>> curr(cols, vector<int>(cols, 0));

        // Initialize base case: last row
        for (int col1 = 0; col1 < cols; col1++) {
            for (int col2 = 0; col2 < cols; col2++) {
                if (col1 == col2)
                    next[col1][col2] = grid[rows-1][col1];
                else
                    next[col1][col2] = grid[rows-1][col1] + grid[rows-1][col2];
            }
        }

        // Fill from bottom to top
        for (int row = rows-2; row >= 0; row--) {
            for (int col1 = 0; col1 < cols; col1++) {
                for (int col2 = 0; col2 < cols; col2++) {

                    int maxCherries = 0;

                    // Try all 9 possible moves
                    for (int move1 = -1; move1 <= 1; move1++) {
                        for (int move2 = -1; move2 <= 1; move2++) {
                            int newCol1 = col1 + move1;
                            int newCol2 = col2 + move2;

                            if (newCol1 >= 0 && newCol1 < cols && newCol2 >= 0 && newCol2 < cols) {
                                maxCherries = max(maxCherries, next[newCol1][newCol2]);
                            }
                        }
                    }

                    int cherry = grid[row][col1];
                    if (col1 != col2) {
                        cherry += grid[row][col2];
                    }

                    curr[col1][col2] = cherry + maxCherries;
                }
            }
            // Move current row to next
            next = curr;
        }

        return next[0][cols-1];
    }
};

