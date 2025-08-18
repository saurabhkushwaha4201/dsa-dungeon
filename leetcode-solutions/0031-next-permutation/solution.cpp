class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());


        // find break Point
        int breakPt = -1;
        int n = nums.size();
        
        for(int i = n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                breakPt = i-1;
                break;
            }
        }
        if(breakPt == -1)
        reverse(nums.begin(),nums.end());
        else {
            // swapping Step
            int swapIdx = -1;
            for(int right = n-1;right>=breakPt+1;right--)
            {
                if(nums[right]>nums[breakPt])
                {
                    swapIdx = right;
                    break;   
                }
            }
            swap(nums[breakPt],nums[swapIdx]);

            // Reversing Step
            int i = breakPt +1;
            int j = n-1;
            while(i<j)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        
    }
};
