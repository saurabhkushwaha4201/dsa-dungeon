class Solution {
public:
    int n;
    unordered_map<long long, long long>mpp;
    
    long long solve(vector<long long>&power, int index, vector<long long>&dp){
        if(index>=power.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int j = lower_bound(power.begin()+index+1,power.end(),power[index]+3) - power.begin();
        // skip
        long long skip = solve(power,index+1,dp);

        // take
        long long take = power[index]*mpp[power[index]] + solve(power,j,dp);

        return dp[index] = max(skip,take);
    }
    long long maximumTotalDamage(vector<int>& power) {
        n = power.size();

        for(int i = 0;i<n;i++){
            mpp[power[i]]++;
        }
        vector<long long> nums;
        for (auto &it : mpp) {
            nums.push_back(it.first);
        }

        sort(nums.begin(),nums.end());
        // vector<long long>dp(nums.size()+1,-1);
        // return solve(nums,0,dp);
        int m = nums.size();
        vector<long long>dp(m+1,0);
       
        for(int index = m-1;index>=0;index--){

            int j = upper_bound(nums.begin()+index+1,nums.end(),nums[index]+2) - nums.begin();
            // skip
            long long skip =(index+1<m? dp[index+1]:0);

            // take
            long long take = nums[index]*mpp[nums[index]] + ((j<m)? dp[j]:0);

            dp[index] = max(skip,take);
        }
        return dp[0];
    }
};
