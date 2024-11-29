class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        if(mpp.size()==nums.size())
        return false;
        return true;
        
    }
};
