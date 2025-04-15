class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev(n);
        for(int j = 0;j<n;j++)
        {
            prev[j] = matrix[n-1][j];
        }

        for(int i =n-2;i>=0;i--)
        {
            vector<int>curr(n);
            for(int j = 0;j<n;j++)
            {
                int down = prev[j];
                int left = (j > 0)     ? prev[j-1] : INT_MAX;
                int right = (j < n-1)  ? prev[j+1] : INT_MAX;

                curr[j] = matrix[i][j] + min({down, left, right});
            }
            prev = curr;
        }

        int minSum = INT_MAX;
        for(int j = 0;j<n;j++)
        {
            minSum  = min(minSum,prev[j]);
        }
        return minSum;
    }
};
