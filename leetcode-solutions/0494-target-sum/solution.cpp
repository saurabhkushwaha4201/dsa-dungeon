class Solution {
public:
    int solve(vector<int>&nums,int index,int sum,int target,vector<vector<int>>&dp)
    {
        if(index>=nums.size())
        return (sum==target);
        if (sum > target) 
            return 0;

        if(dp[index][sum]!=-1)
        return dp[index][sum];
        int pick = solve(nums,index+1,sum+nums[index],target,dp);
        int notPick = solve(nums,index+1,sum,target,dp);

        return dp[index][sum] = pick + notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>total || (total+target) %2!=0)
        return 0;
        int temp = (total+target)/2;
        
        vector<vector<int>>dp(n+1,vector<int>(temp+1,-1));

        return solve(nums,0,0,temp,dp);
    }
};
