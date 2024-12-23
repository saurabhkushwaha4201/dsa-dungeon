class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        int less = 0;
        int same =0;

        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            {
                less++;
            }
            else if (nums[i]==pivot)
            same++;
        }
        int high = less + same;
        same=less;
        less =0;

        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot){
                ans[less]=nums[i];
                less++;
            }
            else if(nums[i]==pivot)
            {
                ans[same]=nums[i];
                same++;
            }
            else
            {
                ans[high]=nums[i];
                high++;
            }
        }
        return ans;
    }
};
