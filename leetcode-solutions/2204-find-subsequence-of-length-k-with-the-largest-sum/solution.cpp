class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>temp = nums;
        nth_element(temp.begin(),temp.begin()+k-1,temp.end(),greater<int>());
        int kth_largest = temp[k-1];
        int countKthLargest = count(temp.begin(),temp.begin()+k,kth_largest);
        vector<int>result;

        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]>kth_largest)
            {
                result.push_back(nums[i]);
            }
            else if(nums[i]==kth_largest && countKthLargest>0)
            {
                result.push_back(nums[i]);
                countKthLargest--;
            }
            if(result.size()==k)
            break;
        }
        return result;
    }
};
