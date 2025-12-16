class Solution {
public:
    int getBeauty(vector<int>&freq, int x){
        int count = 0;
        for(int val = 50;val>=1;val--){
            count += freq[val];
            if(count>=x){
                return -val;
            }
        }
        return 0;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>freq(51,0),result;
        for(int i = 0;i<k;i++){
            if(nums[i]<0){
                freq[-nums[i]]++;
            }
        }
        result.push_back(getBeauty(freq, x));
        for(int i=k;i<n;i++){
            if(nums[i-k]<0){
                freq[-nums[i-k]]--;
            }
            if(nums[i]<0){
                freq[-nums[i]]++;
            }
            result.push_back(getBeauty(freq, x));
        }
        return result;
    }
};
