class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(),nums1.end(),0LL);
        long long sum2 = accumulate(nums2.begin(),nums2.end(),0LL);

        long long count1 = 0,count2 = 0;

        for(int i = 0;i<nums1.size();i++)
        {
            if(nums1[i]==0)
            count1++;
        }
        for(int j = 0;j<nums2.size();j++)
        {
            if(nums2[j]==0)
            count2++;
        }
        sum1 += count1;
        sum2 += count2;
        if(sum1 > sum2 && count2==0)
        return -1;

        if(sum2 > sum1 && count1==0)
        return -1;

        return max(sum1,sum2);
    }
};
