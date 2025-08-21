class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i  = 0;
        int j = n-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(i<j)
        {
            if(isalnum(s[i])&&isalnum(s[j]))
            {
                if(s[i]==s[j])
                {
                    i++;
                    j--;
                }
                else
                return false;
            }
            else if(!isalnum(s[i]))
            i++;
            else if(!isalnum(s[j]))
            j--;
            else
            return false;
        }
        return true;
    }
};
