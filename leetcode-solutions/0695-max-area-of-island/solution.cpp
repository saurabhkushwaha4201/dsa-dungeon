class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>>& grid, int u, int v) {
        if (u < 0 || u >= grid.size() || v < 0 || v >= grid[0].size() || grid[u][v] == 0)
            return 0;

        grid[u][v] = 0; // Mark as visited
        int count = 1;  // Current cell counts as 1

        for (auto &dir : directions) {
            count += dfs(grid, u + dir.first, v + dir.second);
        }
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount = 0, rows = grid.size(), cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {  // Found an island
                    maxCount = max(maxCount, dfs(grid, i, j));
                }
            }
        }
        return maxCount;
    }
};

