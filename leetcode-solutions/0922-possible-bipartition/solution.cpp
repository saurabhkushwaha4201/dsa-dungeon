class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);

        // Building the adjacency list (converting 1-based index to 0-based)
        for (auto& edge : dislikes) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, -1); // -1 means uncolored
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // If uncolored, start BFS
                color[i] = 0; // Color the node with 0 (starting color)
                q.push(i);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]) {
                        if (color[v] == color[u]) {
                            return false; // Conflict in bipartitioning
                        }
                        if (color[v] == -1) { // If uncolored, assign opposite color
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                    }
                }
            }
        }

        return true; // Successfully bipartitioned
    }
};

