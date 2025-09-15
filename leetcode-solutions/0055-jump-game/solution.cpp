class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPoint =0;
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(i>maxPoint)
            return false;
            maxPoint = max(maxPoint,i+nums[i]);
            if(maxPoint>=nums.size()-1)
            return true;
        }
        if(maxPoint==nums.size()-1)
            return true;
        return false;
    }
};
