class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count  = 0;
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            int digitCount = floor(log10(nums[i]))+1;
           if(digitCount%2==0)
           count++;
        }
        return count;
    }
};
