class Solution {
public:
    bool bfs(vector<vector<int>>& adj, int source, int destination, vector<bool>& visited) {
        queue<int> q;
        q.push(source);
        visited[source] = true;  // Mark the source as visited

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == destination) return true;  // Found destination

            for (int v : adj[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;  // Mark node as visited when pushing into queue
                }
            }
        }
        return false;  // No path found
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;  // Trivial case

        vector<vector<int>> adj(n);
        
        // Construct adjacency list
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Since it's an undirected graph
        }

        vector<bool> visited(n, false);
        return bfs(adj, source, destination, visited);
    }
};
