class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int length=s.length();
        int i= length-1;
        int count=0;
        while(i>=0 && s[i]==' ')
        {
            i--;
        }
        while(i>=0 && s[i]!=' ')
        {
            count++;
            i--;
        }
        return count;
        
    }
};
