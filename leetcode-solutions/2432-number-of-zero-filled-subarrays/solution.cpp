class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int n = nums.size();
        long long count = 0;
        // vector<int>contiguosZeros(n);
        // for(int i = 0;i<nums.size();i++)
        // {
        //     if(nums[i]==0)
        //     {
        //         contiguosZeros[i]  = (i>0)?contiguosZeros[i-1]+1:1;
        //         count += contiguosZeros[i];
        //     }
        // }

        int contiguousZeroes = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                contiguousZeroes = (i>0)?contiguousZeroes+1 : 1;
                count += contiguousZeroes;
            }else
            contiguousZeroes = 0;
        }
        return count;
    }
};
