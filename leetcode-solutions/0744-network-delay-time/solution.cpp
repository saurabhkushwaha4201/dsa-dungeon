#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Create adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);  // Adjacency list
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});  // u -> {v, w}
        }
        
        // Step 2: Initialize priority queue and distance array
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});  // Starting from node k with distance 0
        
        vector<int> distance(n + 1, INT_MAX);  // Distance array initialized to max
        distance[k] = 0;  // Distance from k to itself is 0
        
        // Step 3: Dijkstra's algorithm to find the shortest paths
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Explore neighbors
            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int weight = neighbor.second;
                
                // Relaxation step
                if (dist + weight < distance[adjNode]) {
                    distance[adjNode] = dist + weight;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        
        // Step 4: Find the maximum distance from the source node k
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) {
                return -1;  // If any node is unreachable, return -1
            }
            ans = max(ans, distance[i]);
        }
        
        return ans;  // Return the maximum time taken for all nodes to receive the signal
    }
};

