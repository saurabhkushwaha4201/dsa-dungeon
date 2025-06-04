class Solution {
public:
    int m,n;
    int solve(vector<vector<int>>&matrix, int i, int j ,vector<vector<int>>&dp)
    {
        if(i>=m || j>=n)
        return 0;
        if(matrix[i][j]==0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int down = solve(matrix,i+1,j,dp);
        int right = solve(matrix,i,j+1,dp);
        int diagonal = solve(matrix,i+1,j+1,dp);

        return dp[i][j] = 1 + min({down,right,diagonal});
    }
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));

        int result = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    result += solve(matrix,i,j,dp);
                }
            }
        }
        return result;
    }
};
