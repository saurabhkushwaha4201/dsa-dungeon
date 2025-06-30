class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i = 0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        int length = 0;
        for(auto it:mpp)
        {
            if(mpp.find(it.first + 1)!=mpp.end())
            {
                length = max(length,it.second + mpp[it.first+1]);
            }
        }
        return length;
    }
};
