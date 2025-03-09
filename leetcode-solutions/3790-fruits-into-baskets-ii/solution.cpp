class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int unplacedCount = 0;

    for (int i = 0; i < n; ++i) {
        bool placed = false;
        for (int j = 0; j < baskets.size(); ++j) {
            if (baskets[j] >= fruits[i]) {
                baskets.erase(baskets.begin() + j);
                placed = true;
                break;
            }
        }
        if (!placed) {
            ++unplacedCount;
        }
    }

    return unplacedCount;
    }
};
