class Solution {
public:
    int n;
    // int solve(vector<int>&arr, int index, int k, vector<int>&dp)
    // {
    //     if(index>=arr.size()){
    //         return 0;
    //     }
    //     if(dp[index]!=-1)
    //     return dp[index];
    //     int maxElement = INT_MIN;
    //     int len = 0;
    //     int maxAns = INT_MIN;
    //     for(int j =index ;j<min(index+k,n);j++)
    //     {
    //         len++;
    //         maxElement = max(maxElement,arr[j]);
    //         int total = (maxElement*len) + solve(arr,j+1,k,dp);
    //         maxAns = max(maxAns,total);
    //     }
    //     return dp[index] = maxAns;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        // vector<int>dp(n,-1);
        // return solve(arr,0,k,dp);
        vector<int>dp(n+1,0);

        for(int index = n-1;index>=0;index--)
        {
            int maxElement = INT_MIN;
            int len = 0;
            int maxAns = INT_MIN;
            for(int j =index ;j<min(index+k,n);j++)
            {
                len++;
                maxElement = max(maxElement,arr[j]);
                int total = (maxElement*len) + dp[j+1];
                maxAns = max(maxAns,total);
            }
            dp[index]  = maxAns;
        }
        return dp[0];
    }
};
