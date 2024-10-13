class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;

        // Arrays to store Previous Less Element (PLE) and Next Less Element
        // (NLE)
        vector<int> ple(
            n, -1); // PLE stores the index of the previous less element
        vector<int> nle(n, n); // NLE stores the index of the next less element

        stack<int> st;

        // Calculate PLE (Previous Less Element)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear the stack to reuse it for NLE
        while (!st.empty())
            st.pop();

        // Calculate NLE (Next Less Element)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >arr[i]) {
                nle[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Calculate the sum of minimums of all subarrays
        long long result = 0;

        for (int i = 0; i < n; ++i) {
            // Contribution of arr[i] to the sum of subarray minimums
            long long left = i - ple[i];
            long long right = nle[i] - i;
            result = (result + arr[i] * left * right) % MOD;
        }

        return result;
    }
};
