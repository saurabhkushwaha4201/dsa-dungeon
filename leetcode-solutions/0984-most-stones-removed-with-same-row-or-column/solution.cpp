class Solution {
public:
    vector<int> parent;  // This will store the parent of each node (stone).
    vector<int> rank;    // This will store the rank (or height) of each tree in the disjoint set.

    // The find function uses path compression to speed up future find queries.
    int find(int i) {
        if (i == parent[i])  // If the node is its own parent, it is the root.
            return i;
        // Path compression: Make the node point directly to the root
        return parent[i] = find(parent[i]);
    }

    // Union by rank: Attach the tree with smaller rank to the tree with larger rank.
    void unionByRank(int x, int y) {
        int x_parent = find(x);  // Find the root of the first stone
        int y_parent = find(y);  // Find the root of the second stone
        
        if (x_parent == y_parent)  // If both stones are already connected, do nothing.
            return;

        // Union by rank: Attach the smaller tree to the root of the larger tree.
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;  // Make x's root the parent of y's root.
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;  // Make y's root the parent of x's root.
        } else {
            parent[x_parent] = y_parent;  // Arbitrarily make y's root the parent of x's root.
            rank[x_parent] += 1;  // Increase the rank of the new root.
        }
    }

    // The main function to find how many stones need to be removed.
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();  // Get the number of stones.
        parent.resize(n);  // Resize the parent vector to store n elements.
        rank.resize(n, 1);  // Initialize the rank of each node to 1.

        // Initially, each stone is its own parent (individual set).
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // Set the parent of each stone to itself.
        }

        // Now, we process each pair of stones to see if they can be connected.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // If the stones share the same row or the same column, they can be connected.
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unionByRank(i, j);  // Union the two stones.
                }
            }
        }

        int groups = 0;  // To count the number of distinct connected components (groups of stones).
        
        // Count the number of connected components (groups) by checking the roots.
        for (int i = 0; i < n; i++) {
            if (parent[i] == i)  // If a stone is its own parent, it is the root of a group.
                groups++;
        }

        // To connect all the stones, we only need to keep one stone from each group.
        // Thus, we remove the rest. The number of stones to remove is the total stones
        // minus the number of groups (since each group needs at least one stone).
        return (n - groups);
    }
};

