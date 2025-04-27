class Solution {
public:
    int rows, cols;  // to store number of rows and columns globally

    // Helper function to recursively solve the problem
    int solve(vector<vector<int>>& grid, int row, int col1, int col2, vector<vector<vector<int>>>& dp) {
        // Base case: if the row is beyond the last row
        if (row >= rows)
            return 0;

        // If we already solved this state, return its value
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        // Start collecting cherries from current cells
        int cherry = grid[row][col1];

        // If robots are at different positions, add cherries from both cells
        if (col1 != col2) {
            cherry += grid[row][col2];
        }

        int ans = 0; // to store the best (maximum) cherries from the next moves

        // Explore all 9 possible movements (for each robot: move -1, 0, or +1 in columns)
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newRow = row + 1;
                int newCol1 = col1 + i;  // move robot 1
                int newCol2 = col2 + j;  // move robot 2

                // Check if both robots stay inside the grid boundaries
                if (newCol1 >= 0 && newCol1 < cols && newCol2 >= 0 && newCol2 < cols) {
                    // Calculate the maximum cherries among all possible moves
                    ans = max(ans, solve(grid, newRow, newCol1, newCol2, dp));
                }
            }
        }

        // Save the result in DP table and return it
        return dp[row][col1][col2] = ans + cherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        // Initialize the number of rows and columns
        rows = grid.size();
        cols = grid[0].size();

        // Create a 3D dp table initialized with -1
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));

        // Start the recursion from row 0, robot1 at col0, robot2 at col(cols-1)
        return solve(grid, 0, 0, cols - 1, dp);
    }
};

