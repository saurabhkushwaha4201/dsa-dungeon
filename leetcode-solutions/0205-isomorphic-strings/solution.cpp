class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {

        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char,int>mpp1,mpp2;
        
        for(int i=0;i<s.length();i++)
        {
           // s ka t se mapping
            // mapping phle se hai
            if(mpp1.count(s[i]))
            {
                if(mpp1[s[i]]!=t[i]) // agr mapping match ni hua to 
                return false;
            }
            // mapping kro
            else
            {
                mpp1[s[i]]=t[i];
            }
            // t se s ka mapping
            // mapping agr phle se hai to 
            if(mpp2.count(t[i]))
            {
                if(mpp2[t[i]]!=s[i])//match ni hua to false
                return false;
            }
            // t ka s se mapping
            else
            {
                mpp2[t[i]]=s[i];
            }
        }
        return true;
    }
};
