class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> used;
    int sum = 0;
    for (int x : nums) {
        if (x > 0 && used.find(x) == used.end()) {
            used.insert(x);
            sum += x;
        }
    }
    if (sum > 0)
        return sum;
    return *max_element(nums.begin(), nums.end());
    }
};
