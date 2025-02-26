class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, pair<int, int>>> q; // {steps, {row, col}}
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Mark entrance as visited
        maze[entrance[0]][entrance[1]] = '+';
        q.push({0, {entrance[0], entrance[1]}});

        while (!q.empty()) {
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            // Check all 4 directions
            for (auto& dir : directions) {
                int nRow = row + dir.first;
                int nCol = col + dir.second;

                // Ensure the next position is within bounds and open
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && maze[nRow][nCol] == '.') {
                    // If it's an exit (boundary of the maze), return the answer
                    if (nRow == 0 || nCol == 0 || nRow == m - 1 || nCol == n - 1) {
                        return steps + 1;
                    }

                    // Mark the cell as visited and enqueue the position
                    maze[nRow][nCol] = '+';
                    q.push({steps + 1, {nRow, nCol}});
                }
            }
        }

        // No exit was found
        return -1;
    }
};

