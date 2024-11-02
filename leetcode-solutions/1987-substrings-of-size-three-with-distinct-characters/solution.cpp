class Solution {
public:
    int countGoodSubstrings(string s) 
    {
        int count = 0;
    int n = s.length();

    if (n < 3) return 0;  // Not enough characters for substrings of length 3

    std::unordered_map<char, int> charCount;

    // Initialize the sliding window
    for (int i = 0; i < 3; ++i) {
        charCount[s[i]]++;
    }

    // Check the first window
    if (charCount.size() == 3) {
        count++;
    }

    // Slide the window over the rest of the string
    for (int i = 3; i < n; ++i) {
        charCount[s[i]]++;              // Add the new character to the window

        charCount[s[i - 3]]--;          // Remove the character that's sliding out

        // Remove the character from the map if its count is zero
        if (charCount[s[i - 3]] == 0) {
            charCount.erase(s[i - 3]);
        }

        // Check if the current window has all unique characters
        if (charCount.size() == 3) {
            count++;
        }
    }

    return count;
        
    }
};
