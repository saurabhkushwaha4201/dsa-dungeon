class Solution {
public:
    int binaryReflection(int x) {
        int rev = 0;
        while (x > 0) {
            rev = (rev << 1) | (x & 1);
            x >>= 1;
        }
        return rev;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> v; // {reflection, original}

        for (int x : nums) {
            v.push_back({binaryReflection(x), x});
        }

        sort(v.begin(), v.end());

        vector<int> result;
        for (auto& p : v) {
            result.push_back(p.second);
        }
        return result;
    }
};
