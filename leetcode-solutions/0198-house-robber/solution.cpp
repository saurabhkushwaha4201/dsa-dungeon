class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return nums[0];
        int prev2 = 0;
        int prev = nums[0];
        int curr;
        for(int i =2;i<=n;i++)
        {
            int steal = nums[i-1] + prev2;
            int skip = prev;
            curr = max(steal,skip);
            prev2 = prev;
            prev = curr;

        }
        return prev;
    }
};
