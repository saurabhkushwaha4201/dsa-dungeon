class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& nodeCount, int& edgeCount) {
        visited[node] = true;
        nodeCount++;  // Count this node

        for (int neighbor : adj[node]) {
            edgeCount++;  // Each edge will be counted twice (once per node)
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, nodeCount, edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        // Construct adjacency list (undirected graph)
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int completeCount = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodeCount = 0, edgeCount = 0;
                dfs(i, adj, visited, nodeCount, edgeCount);

                edgeCount /= 2; // Since each edge was counted twice
                if (edgeCount == (nodeCount * (nodeCount - 1)) / 2) {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }
};
