class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int l1=s1.length();
        int l2=s2.length();
        if(l1>l2)
        return false;
        map<char,int>mpp1;
        map<char,int>mpp2;
        for(char ch:s1)
        mpp1[ch]++;
        for(int i=0;i<l1;i++)
        {
            mpp2[s2[i]]++;
        }
        if(mpp1==mpp2)
        return true;
        for(int i=l1;i<l2;i++)
        {
            mpp2[s2[i]]++;
            char left=s2[i-l1];
            if(mpp2[left]==1)
            mpp2.erase(left);
            else
            mpp2[left]--;
            if(mpp1==mpp2)
            return true;
        }
        return false;
    }
};
