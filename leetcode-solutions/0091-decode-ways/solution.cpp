class Solution {
public:

    int n;
    int solve(string& s,int index,vector<int>&dp)
    {
        if(index>=n)
        {
            return 1;
        }
        int oneDigit = 0;
        int twoDigit= 0;
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        if(s[index]!='0')
        {
            oneDigit = solve(s,index+1,dp);
        }
        if(index+1<n && (s[index]=='1'||(s[index]=='2'&& s[index+1]<='6')))
        {
            twoDigit = solve(s,index+2,dp);
        }
        
        return dp[index] = oneDigit + twoDigit;
    }
    int numDecodings(string s) {
        n = s.length();
        vector<int>dp(n+1,-1);
        return solve(s,0,dp);
    }
};
