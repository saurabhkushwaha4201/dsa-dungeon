class Solution {
public: 
    int sumDigit(int num)
    {
        int sum = 0;
        while(num)
        {
            sum += (num%10);
            num = num / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) 
    {
        map<int,int>mpp;
        int maxSum = -1;
        for(int i = 0;i<nums.size();i++)
        {
            int sum = sumDigit(nums[i]);
            if(mpp.count(sum))
            {
                maxSum = max(maxSum,mpp[sum] + nums[i]);
                
            }
            mpp[sum] = max(mpp[sum],nums[i]);
            
        }

        
        
        return maxSum;
        
    }
};
