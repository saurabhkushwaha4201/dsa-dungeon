class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // If start or end are blocked, return -1 immediately
        if (grid[0][0] != 0 || grid[m-1][n-1] != 0) {
            return -1;
        }

        // Directions for 8 possible movements (up, down, left, right, and diagonals)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
                                             {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

        // Priority queue to implement Dijkstra’s algorithm
        priority_queue<P, vector<P>, greater<P>> pq;

        // Distance matrix to store the shortest path to each cell
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));

        // Start from the top-left corner
        pq.push({0, {0, 0}});
        distance[0][0] = 0;

        // Mark the start cell as visited by setting grid[0][0] to 1
        grid[0][0] = 1;

        // Run the priority queue to explore the grid
        while (!pq.empty()) {
            // Extract the node with the minimum distance
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            // If we reach the bottom-right corner, return the distance
            if (row == m - 1 && col == n - 1) {
                return dist + 1; // Distance is 1-based, so we return dist + 1
            }

            // Explore all possible directions
            for (auto& dir : directions) {
                int nRow = row + dir.first;
                int nCol = col + dir.second;

                // Check if the new position is within bounds and not visited
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 0) {
                    // If visiting this node offers a shorter path, update the distance and add it to the queue
                    if (dist + 1 < distance[nRow][nCol]) {
                        distance[nRow][nCol] = dist + 1;
                        pq.push({distance[nRow][nCol], {nRow, nCol}});
                        grid[nRow][nCol] = 1; // Mark this cell as visited
                    }
                }
            }
        }

        // If we finish processing and never reach the bottom-right corner, return -1
        return -1;
    }
};

