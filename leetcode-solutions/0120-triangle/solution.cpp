class Solution {
public:
    int row;
    // int solve(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>&dp)
    // {
    //     if(i==row-1)
    //     {
    //         return triangle[i][j];
    //     }
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
    //     int down = triangle[i][j] + solve(triangle,i+1,j,dp);
    //     int diagonaly = triangle[i][j] + solve(triangle,i+1,j+1,dp);

    //     return dp[i][j] = min(down,diagonaly);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        row = triangle.size();
        // vector<vector<int>>dp(row,vector<int>(row,-1));
        // vector<vector<int>>dp;
        // dp = triangle;
        // for (auto& row : dp) {
        //     fill(row.begin(), row.end(), -1);
        // }

         // return solve(triangle,0,0,dp);

        // Method - 2 Tabulation

        vector<vector<int>>dp;
        dp = triangle;
        for (auto& row : dp) {
            fill(row.begin(), row.end(), -1);
        }
        for (int j = 0; j < row; j++) {
            dp[row - 1][j] = triangle[row - 1][j];
        }

        for(int i = row-2;i>=0;i--)
        {
            for(int j = 0;j<=i;j++)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};
