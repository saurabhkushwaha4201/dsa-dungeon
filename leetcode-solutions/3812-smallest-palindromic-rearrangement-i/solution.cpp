class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int>charFreq(26,0);
        for(char ch:s)
            {
                charFreq[ch-'a']++;
            }
        string leftPart = "";
        char mid = '\0';
        for(int i =0;i<26;i++)
            {
                if(charFreq[i]%2==1)
                {
                    mid = 'a' + i;
                }
                leftPart.append(charFreq[i]/2,'a'+i);
            }
        string rightPart = leftPart;
        reverse(rightPart.begin(),rightPart.end());
        string result = leftPart;
        if (mid != '\0')
            result.push_back(mid);
        result += rightPart;
        
        return result;
    }
};
