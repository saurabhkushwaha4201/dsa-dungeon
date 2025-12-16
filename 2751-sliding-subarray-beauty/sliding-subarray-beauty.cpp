#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    typedef tree<
        pair<long long, int>,
        null_type,
        less<pair<long long, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > ordered_multiset;

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        ordered_multiset os;
        vector<int> result;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                os.insert({nums[i], i});
            }

            if(i >= k-1) {
                if(os.size() < x) {
                    result.push_back(0);
                } else {
                    int xth = os.find_by_order(x-1)->first; // corrected
                    result.push_back(xth);
                }

                // erase outgoing element
                if(nums[i-k+1] < 0) {
                    auto it = os.find({nums[i-k+1], i-k+1}); // corrected
                    if(it != os.end()) os.erase(it);
                }
            }
        }
        return result;
    }
};
