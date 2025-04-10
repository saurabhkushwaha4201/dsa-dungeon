class Solution {
public:

    // int solve(vector<int>&cost,int index,vector<int>&dp)
    // {
    //     if(index>=cost.size())
    //     {
    //         return 0;
    //     }
    //     if(dp[index]!=-1)
    //     return dp[index];
    //     int first = cost[index] + solve(cost,index+1,dp);
        
    //     int second = cost[index]+ solve(cost,index+2,dp);
    //     return dp[index]=min(first,second);
    // }
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        // vector<int>dp(n+1);
        
        // dp[0] = 0;
        // dp[1] = 0;
        // for(int i = 2;i<=n;i++)
        // {
        //     int first = cost[i-1] + dp[i-1];
        //     int second = cost[i-2]+dp[i-2];
        //     dp[i] = min(first,second);
        // }
        // return dp[n];

        int prev2 = 0;
        int prev = 0;
        int curr;
        for(int i =2;i<=n;i++)
        {
            int first = cost[i-1]+prev;
            int second = cost[i-2]+prev2;
            curr = min(first,second);
            prev2 = prev;
            prev = curr;

        }
        return prev;
        

    }
};
