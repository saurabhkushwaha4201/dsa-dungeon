class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string ans = "";
        stack<char>st;
        for(int i =0;i<n;i++)
        {
            while(!st.empty() && k>0 && st.top()>num[i])
            {
                k--;
                st.pop();
                ans.pop_back();
            }
            st.push(num[i]);
            ans+=num[i];
        }
        while(k>0 && !st.empty())
        {
            st.pop();
            ans.pop_back();
            k--;
        }
        
        while(ans.length()>1 && ans[0]=='0')
        {
            ans.erase(ans.begin());
        }

        return ans.length()==0?"0":ans;
    }
    
    
};
