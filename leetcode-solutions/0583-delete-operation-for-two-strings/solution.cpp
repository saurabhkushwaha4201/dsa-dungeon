class Solution {
public:
    int solve(string word1,string word2)
    {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<int>prev(len2+1,0),curr(len2+1);
        for(int i = 1;i<=len1;i++)
        {
            for(int j = 1;j<=len2;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                }
                else
                {
                    curr[j] = max(curr[j-1],prev[j]);
                }
            }
            prev = curr;
        }
        return prev[len2];
    }
    int minDistance(string word1, string word2) {
        int lcsLength = solve(word1,word2);
        int deleteWord1 = word1.length() - lcsLength;
        int deleteWord2 = word2.length() - lcsLength;
        return deleteWord1 + deleteWord2;
    }
};
