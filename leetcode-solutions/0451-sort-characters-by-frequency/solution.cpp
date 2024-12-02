class Solution {
public:
    string frequencySort(string s) 
    {
        map<char,int>mpp;
        for(char ch:s)
        mpp[ch]++;
        string result = "";
        vector<string>bucket(s.length()+1);

        for(const auto& pair :mpp)
        {
            bucket[pair.second].append(pair.second,pair.first);
        }
        for(int i=s.size();i>=0;i--)
        {
            if(!bucket[i].empty())
            result+= bucket[i];
        }
        return result;
        
    }
};
