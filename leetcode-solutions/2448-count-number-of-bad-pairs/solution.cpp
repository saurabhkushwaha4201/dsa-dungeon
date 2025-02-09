class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            goodPairs += mpp[key]; // Count the number of good pairs
            mpp[key]++; // Store the frequency of the adjusted values
        }
        
        return totalPairs - goodPairs; // Total pairs - good pairs = bad pairs
    }
};

