class Solution {
public:
    int solve(string &text1, string &text2, int i, int j, vector<vector<int>>&dp) {
        if (i < 0 || j <0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(text1, text2, i - 1, j - 1, dp);
        }

        return dp[i][j] = max(solve(text1, text2, i - 1, j, dp),solve(text1, text2, i, j - 1, dp));
        
    }

    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>>dp(len1+1, vector<int>(len2+1, -1));
        return solve(text1, text2, len1-1, len2-1, dp);
    }
};

