class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>>adj = {
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {0,1,7},
        {2,6},
        {1,3},
        {2,4}
    };
    
    int knightDialer(int n) {
        vector<vector<int>>dp(n+1,vector<int>(10,0));

        for(int cell = 0;cell<=9;cell++)
        {
            dp[0][cell] = 1;
        }
        for(int i =1;i<n;i++)
        {
            for(int cell = 0;cell<=9;cell++)
            {
                int ans = 0;
                for(auto &jump:adj[cell])
                {
                    ans = (ans + dp[i-1][jump])%MOD;
                }
                dp[i][cell] = ans;
            }

        }
        int result = 0;
        for(int cell = 0;cell<=9;cell++)
        {
            result =(result + dp[n-1][cell] )%MOD;
        }
        return result;
    }
};
