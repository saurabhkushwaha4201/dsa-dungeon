class Solution {
public:
    bool isPattern(string word,string pattern)
    {
        if (word.length() != pattern.length()) {
            return false;
        }
        unordered_map<char,int>mpp1,mpp2;
        
        for(int i=0;i<word.length();i++)
        {
           // word ka pattern se mapping
            // mapping phle se hai
            if(mpp1.count(word[i]))
            {
                if(mpp1[word[i]]!=pattern[i]) // agr mapping match ni hua to 
                return false;
            }
            // mapping kro
            else
            {
                mpp1[word[i]]=pattern[i];
            }
            // pattern se word ka mapping
            // mapping agr phle se hai to 
            if(mpp2.count(pattern[i]))
            {
                if(mpp2[pattern[i]]!=word[i])//match ni hua to false
                return false;
            }
            // pattern ka word se mapping
            else
            {
                mpp2[pattern[i]]=word[i];
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string>ans;
        for(int i=0;i<words.size();i++)
        {
            if(isPattern(words[i],pattern) )
            ans.push_back(words[i]);
        }
        return ans;
        
    }
};
