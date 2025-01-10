class Solution {
public:
    bool isSubset(int temp[],vector<int>&maxFre)
    {
        for(int i=0;i<26;i++)
        {
            if(temp[i]<maxFre[i])
            return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<string>result;
        vector<int>maxFre(26);
        for(auto& word:words2)
        {
            int temp[26] = {0};
            for(char& ch:word)
            {
                temp[ch-'a']++;
                maxFre[ch-'a'] = max(maxFre[ch-'a'],temp[ch-'a']);

            }
        }

        // check for subset

        for(auto& word:words1)
        {
            int temp[26]={0};
            for(char& ch:word)
            {
                temp[ch-'a']++;
            }

            if(isSubset(temp,maxFre))
                {
                    result.push_back(word);
                }
            
        }
        return result;
        
    }
};
