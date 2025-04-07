class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if(nums.size()==1)
        return nums[0];
        int n =  nums.size();
        if(nums[0]!=nums[1])
        return nums[0];
        if(nums[n-1]!=nums[n-2])
        return nums[n-1];
        int left =1;
        
        int right = n-2;
        int mid;
        while(left<=right)
        {
            mid  = (left+right)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }
            else if((mid % 2==0 && nums[mid]==nums[mid+1] )|| (mid % 2!=0 && nums[mid]==nums[mid-1]))
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }

        }
        return -1;
        
        
    }
};
