class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        unordered_map<char,int>allow;
        for(int i=0;i<allowed.size();i++)
        {
            allow[allowed[i]]=1;
        }
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            bool flag=1;
            string temp=words[i];
            for(int j=0;j<temp.length();j++)
            {
                if(allow.find(temp[j])!=allow.end())
                {
                    continue;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                ans++;
            }
        }
        return ans;
        
    }
};
