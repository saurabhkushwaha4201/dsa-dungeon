class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        long long count = 0;
        long long result = 0;
        for(int right = 0;right<n;right++)
        {
            if(nums[right]==maxi)
            count++;
            while(count>=k)
            {
                result += (n-right);
                if(nums[left]==maxi)
                {
                    count--;
                }
                left++;
            }

            
        }
        return result;
    }
};
