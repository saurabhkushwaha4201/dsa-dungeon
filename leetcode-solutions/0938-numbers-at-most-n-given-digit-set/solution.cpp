class Solution {
public:
    int dp[10][2][2];
    int solve(int index, int tight, int validNum,vector<string>&digits,string &s)
    {
        if(index==s.size())
        {
            return validNum ? 1 : 0;
        }

        if(dp[index][tight][validNum]!=-1)
        return dp[index][tight][validNum];

        int totalCount = 0;
        if(validNum==false)
        {
            totalCount += solve(index+1,false,false,digits,s);
        }

        int limit = tight ? s[index] - '0' : 9;
        for(auto  &d :  digits)
        {
            int digit = d[0]- '0';
            if(digit>limit)
            break;
            int newTight = tight && (digit==limit);
            
            totalCount += solve(index+1,newTight,true,digits,s);
        }
        return dp[index][tight][validNum] = totalCount;
        
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,true,false,digits,s);
    }
};
