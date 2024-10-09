class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int openBraces=0;
        int closeBraces=0;
        for(char ch:s)
        {
            if(openBraces>0 && ch==')')
            {
                openBraces--;
            }
            else if(ch=='(')
            {
                openBraces++;
            }
            else
            closeBraces++;
        }
        return (openBraces+closeBraces);
        
    }
};
