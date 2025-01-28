class Solution {
public:
    // Variables to store the number of rows and columns in the grid
    int rows;
    int cols;

    // Directions for moving up, down, left, right in the grid
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Helper function to perform Breadth-First Search (BFS)
    int Bfs(int i, int j, vector<vector<int>>& grid) {
        // Queue to hold the positions to visit
        queue<pair<int, int>> que;
        // Add the starting position (i, j) to the queue
        que.push({i, j});

        // Initialize fishCount with the fish in the starting cell
        int fishCount = grid[i][j];
        // Mark the starting cell as visited by setting its value to 0
        grid[i][j] = 0;

        // Process all the positions in the queue
        while (!que.empty()) {
            // Get the front position from the queue
            i = que.front().first;
            j = que.front().second;

            // Pop the position from the queue
            que.pop();

            // Explore all four directions (up, down, left, right)
            for (auto& dir : directions) {
                int i_ = i + dir[0]; // Calculate the new row index
                int j_ = j + dir[1]; // Calculate the new column index

                // Check if the new position is within bounds and contains fish
                if (i_ >= 0 && i_ < rows && j_ >= 0 && j_ < cols && grid[i_][j_] > 0) {
                    // Add the new position to the queue to visit
                    que.push({i_, j_});
                    // Add the fish count from the new position
                    fishCount += grid[i_][j_];
                    // Mark the new cell as visited by setting its value to 0
                    grid[i_][j_] = 0;
                }
            }
        }

        // Return the total number of fish collected from the connected region
        return fishCount;
    }

    // Main function to find the maximum number of fish we can collect
    int findMaxFish(vector<vector<int>>& grid) {
        // Initialize the number of rows and columns in the grid
        rows = grid.size();
        cols = grid[0].size();
        
        // Variable to keep track of the maximum number of fish collected
        int maxFish = 0;

        // Iterate through each cell in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If the current cell contains fish (grid[i][j] > 0)
                if (grid[i][j] > 0) {
                    // Perform BFS from this cell and update the maxFish value
                    maxFish = max(maxFish, Bfs(i, j, grid));
                }
            }
        }

        // Return the maximum number of fish collected from any connected region
        return maxFish;
    }
};

