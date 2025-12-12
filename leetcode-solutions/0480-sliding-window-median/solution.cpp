#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

class Solution {
public:

    typedef tree<
        pair<long long,int>,
        null_type,
        less<pair<long long,int>>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > ordered_multiset;

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        ordered_multiset os;
        vector<double> result;

        for (int i = 0; i < n; i++) {
            // Insert current element with index for uniqueness
            os.insert({nums[i], i});

            if (i >= k - 1) {

                int m = k / 2;

                if (k % 2 == 1) {
                    // odd window → one middle element
                    double med = os.find_by_order(m)->first;
                    result.push_back(med);
                } else {
                    // even window → average of two middle elements
                    double a = os.find_by_order(m - 1)->first;
                    double b = os.find_by_order(m)->first;
                    result.push_back((a + b) / 2.0);
                }

                // Remove the outgoing element
                os.erase({nums[i - (k - 1)], i - (k - 1)});
            }
        }

        return result;
    }
};

