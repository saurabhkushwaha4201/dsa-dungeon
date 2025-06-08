class Solution {
public:
    // int solve(vector<int>&nums, int left, int right, vector<vector<int>>&dp)
    // {
    //     if(left>right)
    //     return 0;

    //     if(dp[left][right]!=-1)
    //     return dp[left][right];
    //     int maxCoins = INT_MIN;
    //     for(int k = left;k<=right;k++)
    //     {
    //         int coinsFromLeft = solve(nums,left,k-1,dp);
    //         int coinsFromRight = solve(nums,k+1,right,dp);

    //         int currCoins = nums[left-1]*nums[k]*nums[right+1];

    //         int totalCoins = currCoins + coinsFromLeft + coinsFromRight;

    //         maxCoins = max(maxCoins,totalCoins);
    //     }

    //     return dp[left][right] = maxCoins;
    // }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        // vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        // return solve(nums,1,n,dp);

        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        // for(int left = n;left>=1;left--)
        // {
        //     for(int right = 1;right<=n;right++)
        //     {
        //         if(left>right)
        //         continue;
            //     int maxCoins = INT_MIN;
            //     for(int k = left;k<=right;k++)
            //     {
            //         int coinsFromLeft = dp[left][k-1];
            //         int coinsFromRight = dp[k+1][right];

            //         int currCoins = nums[left-1]*nums[k]*nums[right+1];

            //         int totalCoins = currCoins + coinsFromLeft + coinsFromRight;

            //         maxCoins = max(maxCoins,totalCoins);
            //     }
            //     dp[left][right] = maxCoins;
            // }
        // }

        for(int len = 1;len<=n;len++)
        {
            for(int left = 1;left <=n-len+1;left++)
            {
                int right = left + len-1;
                for (int k = left; k <= right; k++) {
                    int coins = nums[left - 1] * nums[k] * nums[right + 1];
                    int total = coins + dp[left][k - 1] + dp[k + 1][right];
                    dp[left][right] = max(dp[left][right], total);
                }
            }
                
        }
        return dp[1][n];
    }
};
