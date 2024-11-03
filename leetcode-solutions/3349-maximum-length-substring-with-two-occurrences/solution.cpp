class Solution {
public:
    int maximumLengthSubstring(string s) 
    {
        int maxi=INT_MIN;
        int left=0;
        int right=0;
        map<char,int>mpp;
        for (int right = 0; right < s.length(); right++) {
            mpp[s[right]]++;  // Increment count of the current character

            // Shrink the window until the condition is met
            while (mpp[s[right]] > 2) {
                mpp[s[left]]--;  // Decrement count for the left character
                if (mpp[s[left]] == 0) {
                    mpp.erase(s[left]);  // Remove character from map if count is 0
                }
                left++;  // Move left pointer to the right
            }

            // Update maximum length
            maxi = std::max(maxi, right - left + 1);
        }
        return maxi;


        
    }
};
