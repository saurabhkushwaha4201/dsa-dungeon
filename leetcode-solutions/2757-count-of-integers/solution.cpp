class Solution {
public:
    int dp[23][2][199];  // dp[pos][tight][sum]: memoization table
    const int MOD = 1e9 + 7;

    // Recursive DP function to count valid numbers up to a given string 'numStr'
    int countNumbers(string &numStr, int minSum, int maxSum, int pos, int isTight, int currSum) {
        // Base case: if we've processed all digits
        if (pos == numStr.length()) {
            // Check if current sum is within the allowed range
            return (currSum >= minSum && currSum <= maxSum) ? 1 : 0;
        }

        // Return memoized result if already computed
        if (dp[pos][isTight][currSum] != -1)
            return dp[pos][isTight][currSum];

        long long totalWays = 0;

        // Determine the upper bound for this digit
        int upperLimit = isTight ? (numStr[pos] - '0') : 9;

        // Try all possible digits at this position
        for (int digit = 0; digit <= upperLimit; digit++) {
            // Update tight flag: stays tight only if digit == upperLimit
            int newTight = isTight && (digit == upperLimit);

            // Move to next position, add digit to sum
            totalWays = (totalWays + countNumbers(numStr, minSum, maxSum, pos + 1, newTight, currSum + digit)) % MOD;
        }

        // Save and return the result
        return dp[pos][isTight][currSum] = totalWays;
    }

    int count(string num1, string num2, int minSum, int maxSum) {
        // Count valid numbers from 0 to num2
        memset(dp, -1, sizeof(dp));
        int countUpToNum2 = countNumbers(num2, minSum, maxSum, 0, 1, 0);

        // Count valid numbers from 0 to num1 (excluding num1 itself)
        memset(dp, -1, sizeof(dp));
        int countUpToNum1 = countNumbers(num1, minSum, maxSum, 0, 1, 0);

        // Check if num1 itself is a valid number
        int sumOfNum1 = 0;
        for (char ch : num1) {
            sumOfNum1 += (ch - '0');
        }

        // If num1 is valid, subtract one less in count
        if (sumOfNum1 >= minSum && sumOfNum1 <= maxSum) {
            countUpToNum1--;
        }

        // Final answer: numbers in [num1, num2] with sum in [minSum, maxSum]
        return (countUpToNum2 - countUpToNum1 + MOD) % MOD;
    }
};

