class Solution {
public:
    int countPartitions(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    int leftSum = 0;
    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
        leftSum += nums[i];
        int rightSum = totalSum - leftSum;
        if ((leftSum % 2 == 0) == (rightSum % 2 == 0)) 
        {
            ++count;
        }
    }

    return count;
    }
};
