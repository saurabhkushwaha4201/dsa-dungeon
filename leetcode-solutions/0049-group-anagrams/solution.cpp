class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,vector<string>>mpp;
        for(int i=0;i<strs.size();i++)
        {
            string word = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mpp[strs[i]].push_back(word);
        }
        vector<vector<string>>ans;
        for(auto i: mpp)
        {
            ans.push_back(i.second);
        }
        return ans;
        
    }
};
