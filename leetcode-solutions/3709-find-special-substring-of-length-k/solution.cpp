class Solution {
public:
    bool hasSpecialSubstring(string s, int k) 
{
    int n = s.length();
    if (k > n) return false;

    for (int i = 0; i <= n - k; ++i) {
        bool temp = true;
        for (int j = 1; j < k; ++j) {
            if (s[i + j] != s[i]) {
                temp = false;
                break;
            }
        }
        // check nd and 3rd condition
        if (temp) {
            if ((i == 0 || s[i - 1] != s[i]) && (i + k == n || s[i + k] != s[i])) {
                return true;
            }
        }
    }
    return false;
        
    }
};
