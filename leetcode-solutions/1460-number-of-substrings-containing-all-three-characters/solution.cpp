class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int left=0;
        int right=0;
        int count=0;
        int n=s.length();
        map<char,int>mpp;
        while(right<n)
        {
            mpp[s[right]]++;
            while(mpp['a']>0&&mpp['b']>0&&mpp['c']>0)
            {
                count += (n-right);
                mpp[s[left]]--;
                left++;
            }
            right++;
        }
        return count;
    }
};
