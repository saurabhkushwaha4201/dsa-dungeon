class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long maxSum = 0;
        int n = happiness.size();
        sort(happiness.rbegin(), happiness.rend());
        int i = 1;
        while(k--){
            int take = max(0,happiness[i-1]-(i-1));
            maxSum += take;
            i++;
        }
        return maxSum;
    }
};