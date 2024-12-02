class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        istringstream word(sentence);
        string temp;
       // vector<string>words;
       int wordPos = 1;
        while(word>>temp)
        {
            if(temp.length()>=searchWord.length() && temp.substr(0,searchWord.length()) == searchWord )
            {
                return wordPos;
            }
            else
            wordPos++;
        }
        return -1;
        
        
        
    }
};
