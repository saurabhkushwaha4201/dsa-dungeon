class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int k = n / 3;

        for(int j = 1;j<=k;j++)
            {
                sum += nums[n-2*j];
            }
        return sum;
    }
};
