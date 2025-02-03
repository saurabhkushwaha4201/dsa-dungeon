class Solution {
public:
    // Directions array for moving up, down, left, and right
    vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    // BFS function to mark an entire island as visited (by setting it to 0)
    void bfs(vector<vector<int>>& grid2, int u, int v) {
        queue<pair<int, int>> q;
        grid2[u][v] = 0; // Mark the starting cell as visited (remove from grid2)
        q.push({u, v}); // Push the first cell to the queue

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Explore all 4 possible directions
            for (auto &dir : directions) {
                int nRow = row + dir.first;  // New row
                int nCol = col + dir.second; // New column

                // Check if the new cell is within bounds and is a land cell (1)
                if (nRow >= 0 && nRow < grid2.size() && 
                    nCol >= 0 && nCol < grid2[0].size() && 
                    grid2[nRow][nCol] == 1) 
                {
                    grid2[nRow][nCol] = 0; // Mark as visited (remove from grid2)
                    q.push({nRow, nCol});  // Push new cell to queue for further exploration
                }
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid2.size();
        int cols = grid2[0].size();
        int count = 0;

        // Step 1: Remove all islands in grid2 that are NOT present in grid1
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If grid2 has an island cell (1) but grid1 does NOT, remove it
                if (grid2[i][j] == 1 && grid1[i][j] != 1) {
                    bfs(grid2, i, j); // Use BFS to remove the entire island
                }
            }
        }

        // Step 2: Count the remaining valid sub-islands
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If grid2 has an island cell (1), it must be a valid sub-island
                if (grid2[i][j] == 1) {
                    bfs(grid2, i, j); // Use BFS to mark the entire island as counted
                    count++; // Increase the count of valid sub-islands
                }
            }
        }

        return count; // Return the total number of sub-islands
    }
};

