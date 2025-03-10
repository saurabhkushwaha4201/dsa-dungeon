class Solution {
public:
    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        unordered_map<char, int> mp;  // To track the count of vowels in the current window.
        vector<int> nextCons(n);       // To track the next consonant after each index.

        int lastConsIdx = n;
        for(int i = n-1; i >= 0; i--) {
            nextCons[i] = lastConsIdx;
            if(!isVowel(word[i])) {  // Update the next consonant index.
                lastConsIdx = i;
            }
        }

        int i = 0, j = 0;
        long long count = 0;
        int cons = 0;  // To track the number of consonants in the current window.

        while(j < n) {
            char ch = word[j];
            if(isVowel(ch)) {
                mp[ch]++;  // Count the vowels in the window.
            } else {
                cons++;  // Increment the consonant count.
            }

            // Adjust the left pointer `i` so that consonants don't exceed `k`.
            while(cons > k) {
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);  // Remove the vowel from the map if its count becomes 0.
                    }
                } else {
                    cons--;  // Decrease consonant count.
                }
                i++;  // Move the left pointer.
            }

            // If the window is valid (exactly 5 distinct vowels and exactly `k` consonants), count the substrings.
            while(i < n && mp.size() == 5 && cons == k) {
                int idx = nextCons[j];  // Get the next consonant index after `j`.
                count += idx - j;       // Add the number of valid substrings ending at `j`.

                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);  // Clean up the vowel if its count becomes 0.
                    }
                } else {
                    cons--;  // Decrease consonant count.
                }
                i++;  // Move the left pointer.
            }

            j++;  // Move the right pointer to expand the window.
        }

        return count;
    }
};

