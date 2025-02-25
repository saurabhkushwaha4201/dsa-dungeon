class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;

    void dfs(int row, int col, vector<vector<int>>& land, vector<vector<bool>>& visited, int& minRow, int& minCol, int& maxRow, int& maxCol) {
        visited[row][col] = true;
        minRow = min(minRow, row);
        minCol = min(minCol, col);
        maxRow = max(maxRow, row);
        maxCol = max(maxCol, col);
        
        for (auto dir : directions) {
            int nRow = row + dir.first;
            int nCol = col + dir.second;
            if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && land[nRow][nCol] == 1 && !visited[nRow][nCol]) {
                dfs(nRow, nCol, land, visited, minRow, minCol, maxRow, maxCol);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 1 && !visited[i][j]) {
                    int minRow = i, minCol = j, maxRow = i, maxCol = j;
                    dfs(i, j, land, visited, minRow, minCol, maxRow, maxCol);
                    result.push_back({minRow, minCol, maxRow, maxCol});
                }
            }
        }
        
        return result;
    }
};

