class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) 
{
    int n = nums.size();
    int maxDiff = INT_MIN;
        for(int i=0;i<nums.size()-1;i++)
            {
                maxDiff = max(maxDiff,abs(nums[i]-nums[i+1]));
            }
        maxDiff = max(maxDiff,abs(nums[0]-nums[n-1]));

    return maxDiff;
    }
};
