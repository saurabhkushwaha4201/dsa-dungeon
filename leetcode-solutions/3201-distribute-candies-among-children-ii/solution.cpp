class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        // Try all possible values for the first child
        int minCh1 = max(0, n - 2 * limit);
        int maxCh1 = min(n, limit);

        for (int i = minCh1; i <= maxCh1; ++i) {
            int remaining = n - i; // candies left for child 2 and 3

            // Child 2 can have between max(0, remaining - limit) and min(remaining, limit)
            int minCh2 = max(0, remaining - limit);
            int maxCh2 = min(remaining, limit);

            ways += (maxCh2 - minCh2 + 1);
        }

        return ways;
    }
};

