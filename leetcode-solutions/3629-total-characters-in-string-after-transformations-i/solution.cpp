class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
       vector<int> freq(26, 0);
       int MOD = 1e9 + 7;
        for (char ch : s)
            freq[ch - 'a' ]++;

        for(int i = 0;i<t;i++)
        {
            vector<int>temp(26,0);
            for(int i =0;i<26;i++)
            {
                if(i==25)
                {
                    temp[0] = (temp[0] + freq[25]) % MOD;
                    temp[1] = (temp[1] + freq[25]) % MOD;
                }
                else
                {
                    temp[i+1] = (temp[i+1] + freq[i]) % MOD;
                }
            }
            freq = temp;
        }
        int result = 0;
        for(int i = 0;i<26;i++)
        {
            result = (result + freq[i]) % MOD;
        }
        return result;
    }
};
