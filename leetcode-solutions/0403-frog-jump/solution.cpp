class Solution {
public:
    unordered_map<int,int>mpp;
    int n;
    vector<vector<int>>dp;
    bool solve(vector<int>&stones,int currStoneIndex,int preJump,vector<vector<int>>& dp)
    {
        if(currStoneIndex == n-1)
        return true;
        if(dp[currStoneIndex][preJump]!=-1)
        return dp[currStoneIndex][preJump];
        bool result = false;
        for(int nextJump = preJump - 1; nextJump<=preJump+1 ; nextJump++)
        {
            if(nextJump>0)
            {
                int nextStone = stones[currStoneIndex] + nextJump;

                if(mpp.find(nextStone)!=mpp.end())
                {
                    result = result || solve(stones,mpp[nextStone],nextJump,dp);
                }

            }
        }
        return dp[currStoneIndex][preJump] =result;

    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[1] != 1) return false;
        dp = vector<vector<int>>(n, vector<int>(n, -1));

        for(int i = 0;i<stones.size();i++)
        {
            mpp[stones[i]] = i;
        }
        return solve(stones,0,0,dp);
    }
};
