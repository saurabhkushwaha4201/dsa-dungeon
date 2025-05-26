class Solution {
public:
    // int solve(vector<int>&prices, int index, int canBuy,int trans, vector<vector<vector<int>>>&dp)
    // {
    //     if(index==prices.size() || trans==0)
    //     {
    //         return 0;
    //     }
    //     if(dp[index][canBuy][trans]!=-1)
    //     return dp[index][canBuy][trans];
    //     int profit = 0;
    //     if(canBuy==1) // buy = 1 means we have to buy
    //     {
            
    //         int buy = (-prices[index]) + solve(prices,index+1,0,trans, dp);
    //         int notBuy = solve(prices, index+1, 1,trans, dp);
    //         profit = max(buy, notBuy);
            
    //     }
    //     else    // buy = 0 means we have to sell
    //     {
            
    //         int sell = prices[index] + solve(prices, index+1, 1,trans-1, dp);
    //         int notSell = solve(prices, index+1, 0,trans, dp);
    //         profit = max(sell, notSell);
    //     }
    //     return dp[index][canBuy][trans] =  profit;
    // }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solve(prices, 0, 1,k, dp);
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int index = n-1;index>=0;index--)
        {
            for(int canBuy = 0;canBuy<=1;canBuy++)
            {
                for(int trans = 1;trans<=k;trans++)
                {
                    int profit = 0;
                    if(canBuy)
                    {
                        int buy = (-prices[index]) + dp[index+1][0][trans];
                        int notBuy = dp[index+1][1][trans];
                        profit = max(buy,notBuy);
                    }
                    else
                    {
                        int sell = prices[index] + dp[index+1][1][trans-1];
                        int notSell = dp[index+1][0][trans];
                        profit = max(sell,notSell);
                    }
                    dp[index][canBuy][trans] = profit;
                }
                
            }
        }
        return dp[0][1][k];
    }
};
