class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int minDiff=nums[k-1]-nums[0];
        int j=1;
        for(int i=k;i<nums.size();i++)
        {
            minDiff=min(minDiff, nums[i]-nums[j]);
            j++;
        }
        return minDiff;
        
    }
};
