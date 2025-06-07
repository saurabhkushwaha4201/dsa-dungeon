class Solution {
public:
    int n;
    int solve(int index, vector<int>&stoneValue,vector<int>&dp)
    {
        if(index>=n)
        return 0;
        if(dp[index]!=-1)
        return dp[index];
        int result = INT_MIN;
        result = max(result,stoneValue[index] - solve(index+1,stoneValue,dp));
        if(index+1<n)
        result = max(result,stoneValue[index] + stoneValue[index+1] - solve(index+2,stoneValue,dp));
        if(index+2<n)
        result = max(result, stoneValue[index] + stoneValue[index+1] + stoneValue[index+2] - solve(index+3,stoneValue,dp));

        return dp[index] =  result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<int>dp(n+1,-1);
        int result = solve(0,stoneValue,dp);
        if(result>0)
        return "Alice";
        else if(result<0)
        return "Bob";
        else
        return "Tie";
    }
};
