class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        vector<int>ans;
        int maxPossibleXor = (1 << maximumBit) - 1;
        int prefixXor =0;
        for(int i=0;i<nums.size();i++)
        {
            prefixXor^=nums[i];
        }
  
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans.push_back(prefixXor^maxPossibleXor);
            prefixXor ^= nums[i]; 
        }
        
        return ans;
        
    }
};
