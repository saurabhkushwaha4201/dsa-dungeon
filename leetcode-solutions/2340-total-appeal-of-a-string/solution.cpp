class Solution {
public:
    long long appealSum(string s) 
    {
        long long totalAppeal = 0;
        int n = s.size();
        vector<int> lastSeen(26, -1);

        for (int i = 0; i < n; ++i) {
            lastSeen[s[i] - 'a'] = i;
            for (int j = 0; j < 26; ++j) {
                if (lastSeen[j] != -1) {
                    totalAppeal += (lastSeen[j] + 1);
            }
        }
    }

    return totalAppeal;

   
    }
};
