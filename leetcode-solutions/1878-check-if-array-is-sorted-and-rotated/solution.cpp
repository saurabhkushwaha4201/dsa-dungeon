class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int pivot = 0;
        int size = nums.size();
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i] > (nums[(i+1)% size] ))
            {
                pivot++;
            }
        }
        return pivot <=1;        
    }
};
