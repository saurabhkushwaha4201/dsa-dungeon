class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        if (nums.empty()) {
            return 0; // Return 0 if the vector is empty
        }
        int max_value= *max_element(nums.begin(),nums.end());
        int len=1;
        int temp_len=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==max_value)
            {
                temp_len++;
                len=max(len  ,temp_len);
            }
            else
            {
                temp_len=0;
            }
            
        }
        return len;
        
    }
};
