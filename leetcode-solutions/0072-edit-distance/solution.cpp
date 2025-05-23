class Solution {
public:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>&dp)
    {
        if(i==0)
        {
            return j;
        }
        if(j==0)
        return i;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s1[i-1]==s2[j-1])
        {
            return dp[i][j] = solve(s1, s2, i-1,j-1,dp);
        }
        else
        {
            int insertCh = 1 + solve(s1,s2,i,j-1,dp);
            int deleteCh = 1 + solve(s1,s2,i-1,j,dp);
            int replaceCh = 1 + solve(s1,s2,i-1,j-1,dp);
            return dp[i][j] = min({insertCh,deleteCh,replaceCh});

        }
        return -1;
        
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        // return solve(word1, word2, m, n, dp);

        vector<vector<int>>dp1(m+1,vector<int>(n+1,0));

        for(int i = 0;i<=m;i++)
        {
            for(int j =0 ;j<=n;j++)
            {
                if(i==0 || j==0)
                dp1[i][j] = i+j;
                else if(word1[i-1]==word2[j-1])
                {
                    dp1[i][j] = dp1[i-1][j-1];
                }
                else
                {
                    int insertCh = 1 + dp1[i][j-1];
                    int deleteCh = 1 + dp1[i-1][j];
                    int replaceCh = 1 + dp1[i-1][j-1];
                    dp1[i][j] = min({insertCh,deleteCh,replaceCh});

                }
            }
        }
        return dp1[m][n];
    }
};
