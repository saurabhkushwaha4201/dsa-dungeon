class Solution {
public:
    int solve(int start , int end, bool turn,vector<int>&piles,vector<vector<int>>&dp)
    {
        if(start>end)
        return 0;

        if(dp[start][end]!=-1)
        return dp[start][end];
        if(turn)
        {
            int choice1 = piles[start] + solve(start+1,end,false,piles,dp);
            int choice2 = piles[end] + solve(start,end-1,false,piles,dp);
            return dp[start][end] =  max(choice1,choice2);
        }
        else
        {
            int choice1 = -piles[start] + solve(start+1,end,true,piles,dp);
            int choice2 = -piles[end] + solve(start,end-1,true,piles,dp);
            return dp[start][end] = max(choice1,choice2);
        }
        
    }
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,true,piles,dp)>0;
    }
};
