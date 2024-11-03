class Solution {
public:
    int countKConstraintSubstrings(string s, int k) 
    {
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            int zerosCount=0;
            int onesCount=0;
            for(int j=i;j<s.length();j++)
            {
                if(s[j]=='0')
                zerosCount++;
                else
                onesCount++;
                if(zerosCount <= k || onesCount <= k)
                count++;
                else
                break;
            }
        }
        return count;

        
    }
};
