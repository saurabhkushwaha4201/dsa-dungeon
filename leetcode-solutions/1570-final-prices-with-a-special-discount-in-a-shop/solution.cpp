class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;

        stack<int>st;
        for(int i =n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()>nums[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                result.push_back(nums[i]);
            }
            else
            {
               result.push_back(nums[i]-st.top());
            }
            st.push(nums[i]);
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};
