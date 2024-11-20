class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi = 0;
        map<int, int> mpp;
        int left = 0;
        int right = 0;
        long long sum = 0;
        while (right < k) {
            mpp[nums[right]]++;
            sum += nums[right];
            right++;
        }
        while (right < nums.size()) {
            if (mpp.size() == k) {
                maxi = max(maxi, sum);
            }

            mpp[nums[right]]++;
            sum += nums[right];
            mpp[nums[left]]--;
            if (mpp[nums[left]] == 0)
                mpp.erase(nums[left]);
            sum -= nums[left];

            left++;

            right++;
        }
        if (mpp.size() == k) {
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};
