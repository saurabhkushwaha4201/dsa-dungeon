class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) 
    {
        int maxi=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1;
            while( j < nums.size() && ( abs(nums[j]-nums[i]) <= min(nums[j],nums[i]) ) )
            {
                maxi=max(maxi,nums[i]^nums[j]);
                j++;
            }
        }
        return maxi;
    }
};
