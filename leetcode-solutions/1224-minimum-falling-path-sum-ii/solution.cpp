class Solution {
public:
    int n;
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp )
    {
        if(j<0 || j>=n)
        {
            return INT_MAX;
        }
        if(i==n-1)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=INT_MAX)
        {
            return dp[i][j];
        }
        
        
        int mini = INT_MAX;
        for(int k = 0;k<n;k++)
        {
            if(k!=j)
            {
                mini = min(mini,solve(i+1,k,grid,dp));
            }
        }
        return dp[i][j] = grid[i][j] + mini;

    }
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        n = grid.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX));
        int minSum = INT_MAX;
        for(int j = 0;j<n;j++)
        {
            minSum = min(minSum,solve(0,j,grid,dp));
        }
        return minSum;
        
    }
};
