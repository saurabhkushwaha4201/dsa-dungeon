class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int closestSum = 1000000;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-2;i++)
        {
            int j = i+1;
            int k = n-1;

            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target-sum) < abs(target-closestSum))
                {
                    closestSum = sum;
                }
                if(sum>target)
                {
                    k--;
                }
                else if(sum< target)
                j++;
                else
                return sum;
            }
        }
        return closestSum;
        
    }
};
