
class Solution {
public:
    // Function to check if the word starts and ends with a vowel
    bool startsAndEndsWithVowel(const string& word, const unordered_set<char>& vowels) {
        char firstChar = word[0];
        char lastChar = word[word.length() - 1];
        
        // Check if both the first and last characters are vowels
        return vowels.find(firstChar) != vowels.end() && vowels.find(lastChar) != vowels.end();
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};  // Set of vowels
        int n = words.size();
        
        // Initialize the prefixSum array to store the cumulative count of words
        vector<int> prefixSum(n, 0);
        
        // Check the first word and initialize prefixSum[0]
        if (startsAndEndsWithVowel(words[0], vowels)) {
            prefixSum[0] = 1;  // First word starts and ends with a vowel
        } else {
            prefixSum[0] = 0;  // First word does not start and end with a vowel
        }
        
        // Loop to calculate prefix sum for all words
        for (int i = 1; i < n; i++) {
            if (startsAndEndsWithVowel(words[i], vowels)) {
                // If the current word starts and ends with a vowel, increment the count
                prefixSum[i] = prefixSum[i - 1] + 1;
            } else {
                // Otherwise, just carry forward the previous count
                prefixSum[i] = prefixSum[i - 1];
            }
        }
        
        // Now we will process each query
        vector<int> ans(queries.size());
        
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            // If l == 0, the answer is simply prefixSum[r]
            if (l == 0) {
                ans[i] = prefixSum[r];
            } else {
                // Otherwise, subtract prefixSum[l-1] from prefixSum[r]
                ans[i] = prefixSum[r] - prefixSum[l - 1];
            }
        }

        return ans;
    }
};

