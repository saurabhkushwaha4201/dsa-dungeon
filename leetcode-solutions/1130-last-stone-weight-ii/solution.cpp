class Solution {
public:
    int solve(vector<int>& stones,int index,int sum,int weights, vector<vector<int>>&dp)
    {
        if(index>=stones.size())
        return 0;

        if(dp[index][sum]!=-1)
        return dp[index][sum];

        int pick = INT_MIN;
        if(sum + stones[index]<=weights/2)
        pick = stones[index] + solve(stones,index+1,sum + stones[index],weights,dp);
        int notPick = solve(stones,index+1,sum,weights,dp);
        
        return dp[index][sum] = max(pick,notPick);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int weights = accumulate(stones.begin(),stones.end(),0);
        // vector<vector<int>>dp(n+1,vector<int>(weights/2 + 1, -1));
        // int best =  solve(stones,0,0,weights,dp);
        int target = weights/2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Bottom-up tabulation
        for (int i = 1; i <= n; ++i) {
            int stone = stones[i - 1];
            for (int j = 0; j <= target; ++j) {
                int notPick = dp[i - 1][j];
                int pick = (j >= stone) ? stone + dp[i - 1][j - stone] : 0;
                dp[i][j] = max(pick, notPick);
            }
        }

        int closestSum = dp[n][target];
        return weights - 2 * closestSum;
        
    }
};
