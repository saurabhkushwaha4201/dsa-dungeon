class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
    unordered_map<int, vector<int>> positions;
    for (int i = 0; i < n; i++) {
        positions[nums[i]].push_back(i);
    }
    
    vector<int> minDist(n, -1);
    for (auto& p : positions) {
        vector<int>& indices = p.second;
        if (indices.size() < 2) continue;
        sort(indices.begin(), indices.end());
        int m = indices.size();
        for (int j = 0; j < m; j++) {
            int current = indices[j];
            int prev_idx = indices[(j - 1 + m) % m];
            int next_idx = indices[(j + 1) % m];
            int d_prev = abs(current - prev_idx);
            int d_next = abs(next_idx - current);
            d_prev = min(d_prev, n - d_prev);
            d_next = min(d_next, n - d_next);
            minDist[current] = min(d_prev, d_next);
        }
    }
    
    vector<int> result;
    for (int q : queries) {
        result.push_back(minDist[q]);
    }
    
    return result;
    }
};
