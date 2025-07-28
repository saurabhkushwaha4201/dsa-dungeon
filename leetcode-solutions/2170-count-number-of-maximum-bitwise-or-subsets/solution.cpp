class Solution {
public:
    int maxOr = 0;
    int solve(int i,int currOr, vector<int>&nums)
    {
        if(i==nums.size())
        {
            return currOr == maxOr;
        }
        int take = solve(i+1,currOr | nums[i],nums);
        int notTake = solve(i+1,currOr,nums);
        return take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            maxOr  = maxOr | nums[i];
        }
        return solve(0,0,nums);
    }
};
