class Solution {
public:
    void solve(int opening, int closing,vector<string>&ans,string temp)
    {
        if(opening==0 && closing==0)
        {
            ans.push_back(temp);
            return;
        }
        

        if(opening)
        {
            temp.push_back('(');
            solve(opening -1 ,closing,ans,temp);
            temp.pop_back();
        }
        if(closing>opening)
        {
            temp.push_back(')');
            solve(opening,closing - 1,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,n,ans,"");
        return ans;
    }
};
