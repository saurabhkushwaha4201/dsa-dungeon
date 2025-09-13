class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        double avg = (double)sum/nums.size();
        unordered_set<int>st(nums.begin(),nums.end());

        int ans = max(1,(int)avg +1);
        while(st.count(ans))
            {
                ans++;
            }
        return ans;
    }
};
