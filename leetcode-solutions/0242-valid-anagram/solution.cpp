class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        map<char,int>mpp1,mpp2;
        for(int i=0;i<s.length();i++)
        mpp1[s[i]]++;
        for(int i=0;i<t.length();i++)
        mpp2[t[i]]++;
        return (mpp1==mpp2);
        
    }
};
