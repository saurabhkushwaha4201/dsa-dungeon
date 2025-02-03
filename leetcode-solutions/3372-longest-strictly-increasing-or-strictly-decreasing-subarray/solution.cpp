class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int maxIncreasing = 1;
        int maxDecreasing = 1;
        int maxLength = 1;

        for(int i =0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                maxDecreasing++;
                maxIncreasing = 1;
            }
            else if (nums[i]<nums[i+1])
            {
                maxIncreasing++;
                maxDecreasing = 1;
            }
            else
            {
                maxIncreasing = 1;
                maxDecreasing = 1;
            }
            maxLength = max(maxLength,max(maxIncreasing,maxDecreasing));
        }
        return maxLength;
        
    }
};
