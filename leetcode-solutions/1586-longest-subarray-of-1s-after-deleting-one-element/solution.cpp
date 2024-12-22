class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int right = 0;
        int onesCount = 0;
        int maxSubarray = INT_MIN;
        int left=0;
        while(right<nums.size())
        {
            if(nums[right]==0)
            onesCount++;
            while(onesCount>1)
            {
                if(nums[left]==0)
                onesCount--;
                left++;
            }
            maxSubarray = max(maxSubarray,right-left+1);
            right++;
        }
        return maxSubarray-1;
        
    }
};
