class Solution {
public:
    bool isZeroArray(vector<int>nums,vector<vector<int>>queries,int k)
    {
        vector<int>diff(nums.size(),0);
        for(int i =0;i<=k;i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];
            diff[start]+= val;
            if(end+1 < nums.size())
            {
                diff[end+1]-= val;
            }
        }
        int currSum = 0;
        for(int i= 0;i<nums.size();i++)
        {
            currSum += diff[i];
            diff[i] = currSum;
            if(nums[i]-diff[i]>0)
            return false;

        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        int q = queries.size();

        int low = 0;
        int high = q-1;
        int result = -1;
        int count = 0;
        for(int i =0;i<n;i++)
        {
            if(nums[i]==0)
            count++;
        }
        if(count==n)
        return 0;
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(isZeroArray(nums,queries,mid))
            {
                result = mid+1;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return result;
        
    }
};
