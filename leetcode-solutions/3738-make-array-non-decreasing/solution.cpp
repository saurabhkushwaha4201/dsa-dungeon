class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int>st;
        for(int i =0;i<nums.size();i++)
            {
                int currMax = nums[i];
                while(!st.empty()&&st.top()>currMax)
                    {
                        currMax = max(currMax,st.top());
                        st.pop();
                    }
                st.push(currMax);
            }
        return st.size();
    }
};
