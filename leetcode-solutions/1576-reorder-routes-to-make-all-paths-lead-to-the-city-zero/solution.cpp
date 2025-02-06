class Solution {
public:
    int count = 0; // Counter to keep track of the number of edges that need to be reversed

    // Depth-First Search (DFS) function to traverse the graph
    void dfs(int u, int parent, vector<vector<pair<int, int>>>& adj) {
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;  // The connected node
            int check = neighbor.second; // Check if it's an original directed edge (1) or reversed (0)

            if (v != parent) { // Ensure we don't revisit the parent node
                if (check == 1) // If the edge is in the original direction, we need to reverse it
                    count++;
                dfs(v, u, adj); // Recursive DFS call
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n); // Adjacency list to store the graph with direction info

        // Build the adjacency list
        for (int i = 0; i < connections.size(); i++) {
            int a = connections[i][0]; // Directed edge from `a` to `b`
            int b = connections[i][1];

            adj[a].push_back({b, 1}); // Original direction (needs reversal)
            adj[b].push_back({a, 0}); // Reverse edge (doesn't need change)
        }

        dfs(0, -1, adj); // Start DFS from node 0, considering -1 as the parent (non-existent)

        return count; // Return the minimum number of edge reversals needed
    }
};

