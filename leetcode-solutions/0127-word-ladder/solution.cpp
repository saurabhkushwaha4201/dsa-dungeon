class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Convert wordList to unordered_set for O(1) lookup
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord is not present, no transformation is possible
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        
        // BFS queue: {current word, transformation steps}
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            // Try changing each character in word
            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i];

                // Try replacing it with every letter a-z
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // If transformed word is found in set
                    if (wordSet.find(word) != wordSet.end()) {
                        if (word == endWord) return steps + 1; // Found shortest path
                        q.push({word, steps + 1});
                        wordSet.erase(word); // Remove to prevent revisits
                    }
                }
                word[i] = originalChar; // Restore original character
            }
        }
        
        return 0; // No valid transformation found
    }
};
