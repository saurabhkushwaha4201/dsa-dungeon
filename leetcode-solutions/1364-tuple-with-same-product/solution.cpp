class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        map<int, int> mpp;
        int n = nums.size();
        
        // Count the frequency of each product
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int product = nums[i] * nums[j];
                mpp[product]++;
            }
        }

        int ans = 0;
        for(auto m : mpp)
        {
            int count = m.second;
            if(count > 1)
            {
                ans += (count * (count - 1) / 2) * 8; // Calculate the total valid quadruples
            }
        }
        
        return ans;
    }
};

