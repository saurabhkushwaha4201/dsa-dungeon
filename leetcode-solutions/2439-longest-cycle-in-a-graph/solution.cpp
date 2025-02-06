class Solution {
public:
    int maxCycleLength = -1; // Stores the maximum cycle length found

    // Depth-First Search (DFS) function to detect cycles and compute their length
    void dfs(vector<int>& edges, int u, vector<bool>& visited, vector<bool>& inRecursion, vector<int>& count) {
        if (u != -1) { // If the node exists
            visited[u] = true;      // Mark the node as visited
            inRecursion[u] = true;  // Mark the node as part of the current recursion path
            
            int v = edges[u]; // Get the next node from the edges array
            
            if (v != -1 && !visited[v]) { // If the next node exists and is not visited
                count[v] = count[u] + 1; // Increase the count (distance from the start of this DFS)
                dfs(edges, v, visited, inRecursion, count); // Recur for the next node
            }
            else if (v != -1 && inRecursion[v]) { // If the next node is already in the recursion stack, a cycle is found
                maxCycleLength = max(maxCycleLength, count[u] - count[v] + 1); // Calculate cycle length
            }

            inRecursion[u] = false; // Backtrack and mark node as not part of recursion path
        }
    }

    // Function to find the longest cycle in the directed graph
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);      // To track visited nodes
        vector<bool> inRecursion(n, false);  // To track nodes in the current DFS path
        vector<int> count(n, 1);             // To store the position of each node in DFS traversal
        
        // Run DFS from each unvisited node
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(edges, i, visited, inRecursion, count);
            }
        }

        return maxCycleLength; // Return the maximum cycle length found
    }
};

