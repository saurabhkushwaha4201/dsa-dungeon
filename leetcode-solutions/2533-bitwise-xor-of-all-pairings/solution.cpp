class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        int xor1 = 0;
        int xor2 = 0;

        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1&1)
        {
            for(int i = 0;i<n2;i++)
            {
                xor1 ^= nums2[i];
            }
        }

        if(n2&1)
        {
            for(int i=0;i<n1;i++)
            {
                xor2 ^= nums1[i];
            }
        }
        return xor1^xor2;
    }
};
