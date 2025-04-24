class Solution {
public:
    int n;
    int solve(int amount,int index, vector<int>&coins,vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 1;
        }
        if(amount<0)
        return 0;
        if(index>=n)
        return 0;

        if(dp[amount][index]!=-1)
        return dp[amount][index];

        int take = solve(amount-coins[index],index,coins,dp);
        int notTake = solve(amount,index+1,coins,dp);
        return dp[amount][index] =  take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n+1,-1));
        return solve(amount,0,coins,dp);
    }
};
