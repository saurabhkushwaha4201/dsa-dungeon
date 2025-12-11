class Solution {
public:
    multiset<long long>mst;
    multiset<long long>::iterator mid;
    void insert_val(int x) {
        if (mst.empty()) {
            mst.insert(x);
            mid = mst.begin();
            return;
        }

        mst.insert(x);

        if (x < *mid) {
            if (mst.size() % 2 == 0)
                mid--;
        } 
        else {
            if (mst.size() % 2 == 1)
                mid++;
        }
    }

    void remove_val(int x) {
        auto it = mst.find(x);
        if (it == mst.end()) return;

        bool leftSide = (x <= *mid);

        // Case 1: removing the median itself
        if (it == mid) {
            auto old = mid;

            if (mst.size() == 1) {
                mst.erase(old);
                return;
            }

            // Move mid before erase
            if (mst.size() % 2 == 0) mid++;   // even -> will become odd -> move right
            else mid--;                       // odd  -> will become even -> move left

            mst.erase(old);
            return;
        }

        // Case 2: element is on left side
        if (leftSide) {
            if (mst.size() % 2 == 0) mid++;   // after erase, size becomes odd
        }
        else {
            if (mst.size() % 2 == 1) mid--;   // after erase, size becomes even
        }

        mst.erase(it);
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>result;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            insert_val(nums[i]);
            if(i>=k-1){
                if(k%2==1){
                    result.push_back(*mid/1.0);
                }else{
                    auto mid2 = next(mid);
                    double avg = (*mid + *mid2)/2.0;
                    result.push_back(avg);
                }
                remove_val(nums[i-k+1]);
            }
        }
        return result;
    }
};