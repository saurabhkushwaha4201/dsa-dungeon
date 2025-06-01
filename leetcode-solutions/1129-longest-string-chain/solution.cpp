class Solution {
public:
    
    bool isPred(string& prev, string& curr)
    {
        int a = prev.length();
        int b = curr.length();

        if(a>=b || (b-a)!=1)
        {
            return false;
        }
        // compare alll equal subsequences

        int i = 0;
        int j = 0;
        while(i<a && j<b)
        {
            if(prev[i]==curr[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return i==a;
    }
    static bool compare(string& word1, string& word2)
    {
        return word1.length()<word2.length();
    }
    // int solve(vector<string>&words, int index, int prevIndex, vector<vector<int>>&dp)
    // {
    //     if(index>=words.size())
    //     {
    //         return 0;
    //     }
    //     if(dp[index][prevIndex+1]!=-1)
    //     return dp[index][prevIndex+1];
    //     int take = 0;
    
    //     // take
    //     if(prevIndex==-1 || isPred(words[prevIndex],words[index]))
    //     {
    //         take = 1 + solve(words,index+1,index,dp);
    //     }
    //     // not Take
    //     int notTake = solve(words,index+1,prevIndex,dp);

    //     return dp[index][prevIndex+1] =  max(take, notTake);
    // }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),compare);
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(words,0,-1,dp);
        vector<int>dp(n,1);
        int maxLen = 1;
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(isPred(words[j],words[i]))
                {
                    dp[i] = max(dp[i],dp[j] +1);
                }
            }
            maxLen = max(maxLen,dp[i]);
        }
        return maxLen;
    }
};
