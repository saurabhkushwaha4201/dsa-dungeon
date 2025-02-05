class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; // Already equal
        
        vector<int> diff;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }
        
        if (diff.size() != 2) return false; // Must differ at exactly two places
        
        int i = diff[0], j = diff[1];
        return s1[i] == s2[j] && s1[j] == s2[i]; // Swap check
    }
};

