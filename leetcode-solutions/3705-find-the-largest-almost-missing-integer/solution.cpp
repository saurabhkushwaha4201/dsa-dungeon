class Solution {
public:
    int largestInteger(vector<int>& nums, int k) 
{
    unordered_map<int, int> countMap;
    unordered_set<int> almostMissingSet;
    int n = nums.size();

    for (int i = 0; i <= n - k; ++i) {
        unordered_set<int> subarraySet;
        for (int j = i; j < i + k; ++j) {
            subarraySet.insert(nums[j]);
        }
        for (int num : subarraySet) {
            countMap[num]++;
            if (countMap[num] == 1) {
                almostMissingSet.insert(num);
            } else {
                almostMissingSet.erase(num);
            }
        }
    }

    int largestAlmostMissing = -1;
    for (int num : almostMissingSet) {
        largestAlmostMissing = max(largestAlmostMissing, num);
    }

    return largestAlmostMissing;
        
    }
};
