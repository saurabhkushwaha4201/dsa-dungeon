#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Map to store the next greater element for each element in nums2
        unordered_map<int, int> ngeMap;
        stack<int> st;

        // Iterate through nums2 to fill the ngeMap
        for (int i = 0; i < nums2.size(); i++) {
            // While stack is not empty and the top of the stack is less than or equal to nums2[i]
            while (!st.empty() && st.top() < nums2[i]) {
                // Pop from stack and map the value to the current nums2[i]
                ngeMap[st.top()] = nums2[i];
                st.pop();
            }
            // Push the current element onto the stack
            st.push(nums2[i]);
        }

        // Prepare the result vector for nums1
        vector<int> result;
        for (int num : nums1) {
            // For each element in nums1, check the map for the next greater element
            result.push_back(ngeMap.count(num) ? ngeMap[num] : -1);
        }

        return result; // Return the final result
    }
};

