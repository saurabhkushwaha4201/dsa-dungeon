class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        // vector<int>dp(n,1);
        // int maxi = 0;
        // for(int i = 1;i<n;i++)
        // {
        //     for(int j = 0;j<i;j++)
        //     {
        //         if(arr[j] + difference==arr[i])
        //         {
        //             dp[i] = max(dp[i],dp[j]+1);
        //         }
        //     }
        //     maxi = max(maxi,dp[i]);
        // }
        // return maxi;
        int maxi = 0;
        unordered_map<int,int>dp;
        for(auto num:arr)
        {
            dp[num] = dp[num-difference] + 1;
            maxi = max(maxi,dp[num]);
        }
        return maxi;
    }
};
