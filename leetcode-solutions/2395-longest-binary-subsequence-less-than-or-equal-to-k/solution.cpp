class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int length = 0;

        long long powerValue = 1;
        int n = s.length();

        for(int i = n-1;i>=0;i--)
        {
            if(s[i]-'0'==0)
            {
                length++;
            }
            else if(1 * powerValue <=k)
            {
                length++;
                k  = k - 1*powerValue;
            }
            if(powerValue<=k)
            powerValue  = powerValue*2;
        }
        return length;
    }
};
