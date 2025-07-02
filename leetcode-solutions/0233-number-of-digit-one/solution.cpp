class Solution {
public:
    int dp[10][2][10];
    int solve(string &s, int index, int tight, int count)
    {
        if(index==s.size())
        {
            return count;
        }

        if(dp[index][tight][count]!=-1)
        return dp[index][tight][count];

        int limit = tight ? s[index] - '0' : 9;
        int totalCount = 0;
        for(int digit = 0;digit<=limit;digit++)
        {
            int newTight = tight && (digit==limit);
            if(digit==1)
            {
                totalCount += solve(s, index + 1, newTight, count+1);
            }
            else
            {
                totalCount += solve(s, index + 1, newTight, count);
            }
        }
        return dp[index][tight][count] = totalCount;
    }
    int countDigitOne(int n) {
        string s= to_string(n);
        memset(dp,-1,sizeof(dp));

        return solve(s,0,true,0);
    }
};
