class Solution {
public:
    bool isArraySpecial(vector<int>& nums) 
    {
        if(nums.size()==1)
        return true;
        for(int i =1;i<nums.size();i++)
        {
            bool previous = (nums[i-1]%2==0);

            if((nums[i] %2==0) != previous)
            {
                continue;
            }
            else
            return false;
        }
        return true;
        
    }
};
