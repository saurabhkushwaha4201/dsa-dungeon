class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxLength = 0; // To store the maximum length of the subarray found
        int n = nums.size(); // Size of the input array
        int left = 0;        // Left pointer to traverse the array

        while (left < n) {
            // Check if the current element is even and within the threshold
            if (nums[left] % 2 == 0 && nums[left] <= threshold) {
                int currentLength = 1; // Initialize the current subarray length
                int right = left;      // Right pointer to find the subarray

                // Traverse the subarray while alternating between even and odd
                // and within the threshold
                while (right + 1 < n && nums[right + 1] <= threshold &&
                       nums[right] % 2 != nums[right + 1] % 2) {
                    currentLength++;
                    right++;
                }

                // Update the maximum length found
                maxLength = max(maxLength, currentLength);
                left =
                    right +
                    1; // Move left to the position after the current subarray
            } else {
                left++; // Move to the next element if the current one doesn't
                        // meet the criteria
            }
        }

        return maxLength; // Return the maximum length of the subarray found
    }
};
