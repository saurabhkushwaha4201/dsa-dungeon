class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        long long result = 0;
        int n = nums.size();
        vector<int>leftMax(n);
        vector<int>rightMax(n);
        for(int i=1;i<n;i++)
        {
            leftMax[i] = max(leftMax[i-1],nums[i-1]);
        }

        for(int j = n-2;j>=0;j--)
        {
            rightMax[j] = max(rightMax[j+1],nums[j+1]);
        }

        for(int k = 1;k<n;k++)
        {
            result = max(result,(long long)(leftMax[k]-nums[k])*rightMax[k]);
        }
        return result;
        
    }
};
