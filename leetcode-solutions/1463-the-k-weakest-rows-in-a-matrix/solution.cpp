class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // Step 1: Create a vector to store the count of soldiers for each row.
        vector<pair<int, int>> soldierCount;  // pair<soldier_count, row_index>
        
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            // Count the number of soldiers in the current row.
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }
            soldierCount.push_back({count, i});  // Store the count and row index.
        }
        
        // Step 2: Use a min-heap (priority queue) to store the rows by soldier count.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        // Push all rows into the priority queue (min-heap).
        for (const auto& entry : soldierCount) {
            minHeap.push(entry);
        }
        
        // Step 3: Extract the first `k` weakest rows.
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(minHeap.top().second);  // Add the row index to the result.
            minHeap.pop();  // Remove the row from the heap.
        }
        
        return result;
    }
};
