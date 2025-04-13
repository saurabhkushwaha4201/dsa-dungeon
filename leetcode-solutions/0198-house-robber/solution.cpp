class Solution {
public:
    int solve(vector<int>&nums,int n, int index, vector<int>&dp)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int take = nums[index] + solve(nums,n,index+2,dp);
        int notTake = solve(nums,n,index+1,dp);
        return dp[index] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,n,0,dp);
    }
};
