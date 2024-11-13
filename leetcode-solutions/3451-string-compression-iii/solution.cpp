class Solution {
public:
    string compressedString(string word) 
    {
        string result="";
        int i=0;
        while(i<word.length())
        {
            int count=0;
            char currentLetter = word[i];
            while(count<9 && i<word.length() && word[i]==currentLetter)
            {
                count++;
                i++;
            }
            result += (count +'0');
            result+=currentLetter;
            
        }
        return result;
    }
};
