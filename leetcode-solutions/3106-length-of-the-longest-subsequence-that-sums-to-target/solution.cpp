class Solution {
public:
    int solve(vector<int>&nums,int target,int index,int n,vector<vector<int>>&dp)
    {
        if(target==0)
        {
            return 0;
        }
        if(target<0 || index>=n)
        {
            return INT_MIN;
        }

        if(dp[index][target]!=-1)
        return dp[index][target];

        int take =1 + solve(nums,target-nums[index],index+1,n,dp);
        // if(take!=INT_MIN)
        // take+=1;
        int notTake = solve(nums,target,index+1,n,dp);
        
        return dp[index][target] = max(take,notTake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int result =  solve(nums,target,0,n,dp);
        if(result<0)
        return -1;
        return result;
    }
};
