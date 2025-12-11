class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        deque<int>dq;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            // check for out of window
            while(!dq.empty()&&dq.front()<=(i-k)){
                dq.pop_front();
            }
            while(!dq.empty()&& nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            // push el
            dq.push_back(i);
            // if window is equal size take max from front
            if(i>=k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;

    }
};