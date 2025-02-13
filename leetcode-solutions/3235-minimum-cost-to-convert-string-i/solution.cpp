

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.length();
        vector<vector<long long>> adj(26, vector<long long>(26, LLONG_MAX));
        
        int length = original.size();
        for (int i = 0; i < length; i++) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            adj[x][y] = min(adj[x][y], (long long)cost[i]);
        }


        // Floyd-Warshall algorithm to find the minimum transformation cost between all pairs of characters
        for (int via = 0; via < 26; via++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (adj[i][via] != LLONG_MAX && adj[via][j] != LLONG_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (source[i] == target[i]) continue;
            if (adj[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX)
             return -1;

            ans += adj[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
};

