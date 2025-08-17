class Solution {
public:
    bool isNumber(string s) {
        
        int n = s.length();
        bool seenDigit = false, seenE = false, digitAfterE = false, seenDot = false;

        for(int i = 0;i<n;i++)
        {
            char ch = s[i];

            if(isdigit(ch))
            {
                seenDigit = true;
                if(seenE)
                digitAfterE = true;
            }
            else if(ch=='.')
            {
                if(seenDot || seenE)
                return false;
                seenDot = true;
            }
            else if(ch=='-' || ch=='+')
            {
                if(i>0 && s[i-1]!='e' && s[i-1]!='E')
                return false;

            }
            else if(ch=='e' || ch=='E')
            {
                if(seenE || !seenDigit)
                return false;
                seenE = true;

                digitAfterE = false;

            }
            else
            return false;
        }
        return seenDigit && (!seenE || digitAfterE);
    }
};
