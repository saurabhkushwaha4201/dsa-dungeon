class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>>pos(26,{-1,-1});
        int n = s.size();
        for(int i = 0;i<n;i++){
            int ch = s[i];
            int id = ch - 'a';
            if(pos[id].first==-1){
                pos[id].first = i;
            }
            pos[id].second = i;
        }
        int ans = 0;
        for(int i = 0;i<26;i++){
            int first = pos[i].first;
            int last = pos[i].second;
            set<char>st;
            for(int j = first +1 ;j<=last-1;j++){
                st.insert(s[j]);
            }
            ans+=st.size();
        }
        return ans;
    }
};
