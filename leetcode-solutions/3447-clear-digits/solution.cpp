class Solution {
public:
    string clearDigits(string s) 
    {
        int i = 0;
        int j =0;
        while(i<s.length())
        {
            if(isdigit(s[i]))
            {
                if(j!=0)
                {
                    j--;
                }
            }
            else
            {
                s[j] = s[i];
                j++;
            }
            i++;
        }
        return s.substr(0,j);

        
    }
};
