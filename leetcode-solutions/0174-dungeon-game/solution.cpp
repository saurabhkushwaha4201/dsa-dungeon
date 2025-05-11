class Solution {
public:
    int m,n;
    int solve(vector<vector<int>>& dungeon,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=m || j>=n )
        return INT_MAX;

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(i==(m-1) && j==(n-1))
        {
            if(dungeon[i][j]>0)
            return 1;

            return abs(dungeon[i][j]) +1;
        }

        

        int right = solve(dungeon,i,j+1,dp);
        int down = solve(dungeon,i+1,j,dp);
        int result = min(right,down) - dungeon[i][j];
        return dp[i][j] = result > 0 ? result : 1;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solve(dungeon,0,0,dp);

        vector<vector<int>>dp(m,vector<int>(n));

        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(i==(m-1) && j==(n-1))
                {
                    if(dungeon[i][j]>0)
                    dp[i][j] = 1;
                    else
                    dp[i][j] = abs(dungeon[i][j]) +1;
                     
                }
                else
                {
                    int right = (j+1>=n) ? INT_MAX: dp[i][j+1];
                    int down = (i+1>=m)? INT_MAX : dp[i+1][j];
                    int result = min(right,down) - dungeon[i][j];
                    dp[i][j] = result > 0 ? result : 1;
                }  
            }
        }
        return dp[0][0];

        
    }
};
