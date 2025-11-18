class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int>mpp;
        int n = nums.size();
        if(n % k!=0){
            return false;
        }
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }
        while(!mpp.empty()){
            int el = mpp.begin()->first;
            for(int i = 0;i<k;i++){
                int curr = el + i;
                if (!mpp.count(curr)) return false;

                mpp[curr]--;
                if (mpp[curr] == 0) {
                    mpp.erase(curr);
                }
            }
        }
        return true;
    }
};
