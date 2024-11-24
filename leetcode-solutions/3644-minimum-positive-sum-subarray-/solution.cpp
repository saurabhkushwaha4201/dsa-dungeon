class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) 
{
    int n = nums.size();
    int minSum = INT_MAX;
    for(int size = l;size<=r;size++)
        {
            int sum = 0;
            // sum of first window
            for(int j=0;j<size;j++)
                {
                    sum += nums[j];
                }
            // if it is valid window
            if(sum>0)
            {
                minSum = min(minSum,sum);
            }

            // sum of next window  till size ans check if it si valid window
            for(int k = size;k<n;k++)
                {
                    sum += nums[k];
                    sum -= nums[k-size];

                    if(sum>0)
                    {
                        minSum = min(minSum,sum);
                    }
                }
        }
    return (minSum == INT_MAX) ? -1 : minSum;
        
}
};
