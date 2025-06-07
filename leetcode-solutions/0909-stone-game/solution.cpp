class Solution {
public:
    int solve(int start , int end,vector<int>&piles,vector<vector<int>>&dp)
    {
        if(start==end)
        return piles[start];

        if(dp[start][end]!=INT_MIN)
        return dp[start][end];
        
        int firstChoice = piles[start] - solve(start+1,end,piles,dp);
        int lastChoice = piles[end] - solve(start,end-1,piles,dp);
        return dp[start][end] = max(firstChoice,lastChoice);
        
    }
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MIN));
        return solve(0,n-1,piles,dp)>0;
    }
};
