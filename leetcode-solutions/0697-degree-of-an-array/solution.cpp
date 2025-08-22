class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,P>mpp;
        int degree = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mpp.find(nums[i]) == mpp.end()) {
                // first time seeing this number
                mpp[nums[i]] = {1, {i, i}};
            } else {
                // update freq and last index
                mpp[nums[i]].first++;
                mpp[nums[i]].second.second = i;
            }
            degree = max(degree, mpp[nums[i]].first);
        }
        int minLength = INT_MAX;
        for (auto& [key, value] : mpp)
        {
            int freq = value.first;
            int startIndex = value.second.first;
            int endIndex = value.second.second;
             if (freq == degree) {
                minLength = min(minLength, endIndex - startIndex + 1);
            }
        }

        return minLength;


    }
};
