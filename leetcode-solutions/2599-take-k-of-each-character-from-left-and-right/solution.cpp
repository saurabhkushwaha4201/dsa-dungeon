class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        int n = s.length();
        if(s.length()<k)
        return -1;
        map<char,int>mpp;
        for(int i=0;i<n;i++)
        mpp[s[i]]++;

        if(mpp['a']<k || mpp['b']<k || mpp['c']<k)
        return -1;
        int extra =0;
        int left=0;
        int right=0;
        map<char,int>mpp2;
        while(right<n)
        {
            mpp2[s[right]]++;
            while (left <= right && ( mpp['a'] - mpp2['a'] < k || mpp['b'] - mpp2['b'] < k || 
                                         mpp['c'] - mpp2['c'] < k)) 
            {
                mpp2[s[left]]--;
                left++;
            }
            extra = max(extra,right-left+1);
            right++;
        }
        return (n-extra);
    }
};
