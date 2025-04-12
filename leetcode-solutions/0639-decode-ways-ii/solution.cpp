class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        const int mod = 1e9 + 7;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                // one digit
                if (s[i] == '*') {
                    dp[i] =
                        (1LL*9 * dp[i + 1]) % mod; // '*' as 1 to 9 for single digit
                } else if (s[i] != '0') {
                    dp[i] = (dp[i + 1]) % mod;
                }

                // two digit
                if (i + 1 < n) {
                    if (s[i] == '1') {
                        if (s[i + 1] == '*') {
                            dp[i] = (dp[i] + 1LL*9 * dp[i + 2]) % mod;
                        } else {
                            dp[i] = (dp[i] + dp[i + 2]) % mod;
                        }
                    }

                    else if (s[i] == '2') {
                        if (s[i + 1] == '*') {
                            dp[i] = (dp[i] + (1LL* 6 * dp[i + 2]) % mod)%mod;
                        } else if (s[i + 1] <= '6') {
                            dp[i] = (dp[i] + dp[i + 2])%mod;
                        }
                    } else if (s[i] == '*') {
                        if (s[i + 1] == '*') {
                            dp[i] = (dp[i] + 1LL* 15 * (dp[i + 2])) % mod;
                        } else if (s[i + 1] <= '6') {
                            dp[i] = (dp[i] +  1LL* 2 * dp[i + 2]) % mod;
                        } else if (s[i + 1] > '6') {
                            dp[i] = (dp[i]+ dp[i + 2])%mod;
                        }
                    }
                }
            }
        }
        return dp[0];
    }
};
