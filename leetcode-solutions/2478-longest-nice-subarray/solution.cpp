class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int maxLength = 1;
        int left = 0;
        int right = 0;
        int mask = 0;
        while(right<nums.size())
        {
            while((mask & nums[right])!=0)
            {
                mask = (mask ^ nums[left]);
                left++;
            }
            maxLength = max(maxLength,right-left+1);
            mask = (mask|nums[right]);
            right++;
        }
        return maxLength;
        
    }
};
