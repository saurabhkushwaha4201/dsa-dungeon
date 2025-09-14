class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int,greater<int>>st(nums.begin(),nums.end());
        vector<int>result;
        auto it = st.begin();
        while (k-- && it != st.end()) {
            result.push_back(*it);
            ++it;
        }
        return result;
    }
};
