class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        int n = nums.size();
        stack<int>st;
        for(int num:nums)
            {
                while(!st.empty() && st.top()>num)
                    {
                        st.pop();
                        operations++;
                    }

                if(num>0 && (st.empty() || st.top()<num))
                {
                    st.push(num);
                }

                
            }
        while(!st.empty())
            {
                st.pop();
                operations++;
            }
        return operations;
    }
};
