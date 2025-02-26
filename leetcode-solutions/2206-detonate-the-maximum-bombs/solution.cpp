class Solution {
public:
    typedef long long LL;

    void dfs(int node, int& count, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;
        count++;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, count, visited, adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n); // Initialize adjacency list with n elements

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];

                // Correct the distance calculation
                LL distance = (LL)(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // Distance squared

                if (distance <= r1 * r1) { // Compare squared distance with square of radius
                    adj[i].push_back(j);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int count = 0;
            dfs(i, count, visited, adj);
            result = max(result, count);
        }

        return result;
    }
};
