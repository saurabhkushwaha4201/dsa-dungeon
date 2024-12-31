class Solution {
public:
    vector<int> diStringMatch(string s) 
    {
        int size = s.length();
        vector<int>ans(size+1);
        int low = 0;
        int high = size;
        for(int i=0;i<=s.length();i++)
        {
            if(s[i]==size || s[i]=='I')
            {
                ans[i] = low;
                low++;
            }
            else
            {
                ans[i]=high;
                high--;
            }
        }
        return ans;
        
    }
};
