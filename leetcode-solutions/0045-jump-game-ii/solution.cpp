class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int n = nums.size();
        int maxPoint;
        if(nums.size()==1)
        return 0;
        int currentRange = 0;
        for(int i = 0;i<n;i++)
        {
            maxPoint = max(maxPoint,i+nums[i]);
            if(currentRange>=n-1)
            return jumps;
            if(i==currentRange){
                jumps++;
                currentRange = maxPoint;
            }
        }
        return jumps;
    }
};
