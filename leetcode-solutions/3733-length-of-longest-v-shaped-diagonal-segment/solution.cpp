class Solution {
public:
    int rows, cols;
    int dp[501][501][4][2];
    vector<vector<int>> diagonal = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int solve(int i, int j, int d, bool canTurn, int val,
              vector<vector<int>>& grid) {
        int new_i = i + diagonal[d][0];
        int new_j = j + diagonal[d][1];

        if (new_i < 0 || new_i >= rows || new_j < 0 || new_j >= cols ||
            grid[new_i][new_j] != val)
            return 0;

        if (dp[new_i][new_j][d][canTurn] != -1)
            return dp[new_i][new_j][d][canTurn];

        int keepMoving =
            1 + solve(new_i, new_j, d, canTurn, val == 2 ? 0 : 2, grid);

        int turn = 0;
        if (canTurn == true) {
            turn =  1 + solve(new_i, new_j, (d + 1) % 4, false, val == 2 ? 0 : 2, grid);
        }

        return dp[new_i][new_j][d][canTurn] = max(turn, keepMoving);
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int result = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d <= 3; d++) {
                        result = max(result, 1 + solve(i, j, d, true, 2, grid));
                    }
                }
            }
        }
        return result;
    }
};
