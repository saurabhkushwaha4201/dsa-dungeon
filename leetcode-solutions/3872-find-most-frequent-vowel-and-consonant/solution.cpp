class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mpp;
        string vowels = "aeiou";

        for (char c : s) {
            mpp[c]++;
        }
        int maxVowelFreq = 0;
        int maxConsFreq = 0;

        for (auto it : mpp) {
            char ch = it.first;
            int count = it.second;
            if (vowels.find(ch) != string::npos) {
                maxVowelFreq = max(maxVowelFreq, count);
            } else {
                maxConsFreq = max(maxConsFreq, count);
            }
        }
        return maxVowelFreq + maxConsFreq;
    }
};
