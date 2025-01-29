class Solution {
public:
    // Directions for moving in 4 possible directions: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Helper function to perform depth-first search (DFS)
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visited)
    {
        // Mark the current cell as visited
        visited[row][col] = 1;

        // Explore the neighboring cells in all 4 directions
        for (auto &dir : directions)
        {
            int nrow = row + dir.first;  // Calculate new row position
            int ncol = col + dir.second; // Calculate new column position

            // Check if the neighbor is within bounds, not visited yet, and part of the land (grid[nrow][ncol] == 1)
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size()
                && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                // If valid, perform DFS on the neighbor
                dfs(grid, nrow, ncol, visited);
            }
        }
    }

    // Function to return the number of enclaves
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int rows = grid.size();       // Get the number of rows in the grid
        int cols = grid[0].size();    // Get the number of columns in the grid
        int count = 0;                // Variable to keep track of the number of enclosed land cells
        vector<vector<int>> visited(rows, vector<int>(cols, 0));  // Initialize visited matrix to track visited cells

        // Step 1: Perform DFS on the boundary rows (top and bottom)
        // For the top row
        for (int j = 0; j < cols; j++)
        {
            if (grid[0][j] == 1 && visited[0][j] == 0)  // If '1' is found and not visited
            {
                dfs(grid, 0, j, visited);  // Run DFS from the top row
            }
        }

        // For the bottom row
        for (int j = 0; j < cols; j++)
        {
            if (grid[rows - 1][j] == 1 && visited[rows - 1][j] == 0)  // If '1' is found and not visited
            {
                dfs(grid, rows - 1, j, visited);  // Run DFS from the bottom row
            }
        }

        // Step 2: Perform DFS on the boundary columns (left and right)
        // For the first column
        for (int i = 0; i < rows; i++)
        {
            if (grid[i][0] == 1 && visited[i][0] == 0)  // If '1' is found and not visited
            {
                dfs(grid, i, 0, visited);  // Run DFS from the left column
            }
        }

        // For the last column
        for (int i = 0; i < rows; i++)
        {
            if (grid[i][cols - 1] == 1 && visited[i][cols - 1] == 0)  // If '1' is found and not visited
            {
                dfs(grid, i, cols - 1, visited);  // Run DFS from the right column
            }
        }

        // Step 3: Count the number of land cells ('1') that are surrounded by water ('0')
        // Traverse the entire grid and count the unvisited land cells (enclaves)
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)  // If '1' is found and not visited (enclave)
                {
                    count++;  // Increment the count of enclaves
                }
            }
        }

        // Return the total number of enclaves
        return count;
    }
};

