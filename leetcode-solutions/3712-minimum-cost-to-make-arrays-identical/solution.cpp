class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) 
{
    
    int n = arr.size();
        
        long long totalModificationCost = 0;
        for (int i = 0; i < n; ++i) {
            totalModificationCost += abs(arr[i] - brr[i]);
        }

        if (arr == brr) {
            return 0;
        }
        
        long long minCost = totalModificationCost;

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        long long rearrangedCost = 0;
        for (int i = 0; i < n; ++i) {
            rearrangedCost += abs(arr[i] - brr[i]);
        }

        minCost = min(minCost, rearrangedCost + k);

        return minCost;
        
    }
};
