class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string,int>mpp;
        for(auto & s:responses)
            {
                unordered_set<string>temp(s.begin(),s.end());
                for(auto & str:temp)
                    {
                        mpp[str]++;
                    }
            }
        string ans;
        int most = 0;
        for(auto it:mpp)
            {
                int count = it.second;
                string temp = it.first;
                if(count > most || (count==most && (temp <ans )))
                {
                    ans = temp;
                    most = count;
                }
            }
        return ans;
    }
};
