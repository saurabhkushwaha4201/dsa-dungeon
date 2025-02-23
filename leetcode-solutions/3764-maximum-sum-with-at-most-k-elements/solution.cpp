class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
    int n = grid.size();
    int m = grid[0].size();
    priority_queue<long long> maxHeap;

    for (int i = 0; i < n; i++) {
        sort(grid[i].rbegin(), grid[i].rend());
        for (int j = 0; j < min(limits[i], m); j++) {
            maxHeap.push(grid[i][j]);
        }
    }

    long long maxSum = 0;
    while (k > 0 && !maxHeap.empty()) {
        maxSum += maxHeap.top();
        maxHeap.pop();
        k--;
    }

    return maxSum;
    }
};
