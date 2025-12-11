class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;     // stores window candidates in decreasing order
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // 1. Remove old value from deque (value that slides out)
            if (i >= k && !dq.empty() && dq.front() == nums[i - k]) {
                dq.pop_front();
            }

            // 2. Maintain decreasing order
            while (!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }

            // 3. Push current value
            dq.push_back(nums[i]);

            // 4. Capture window max
            if (i >= k - 1) {
                ans.push_back(dq.front());
            }
        }

        return ans;
    }
};

