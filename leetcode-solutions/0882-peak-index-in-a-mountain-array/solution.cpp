class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
         // invariant: peak is in [low, high]
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid is on the ascending slope, peak is to the right.
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                // mid is on the descending slope or at the peak
                high = mid;
            }
        }

        // low == high is the peak index
        return low;
    }
};
