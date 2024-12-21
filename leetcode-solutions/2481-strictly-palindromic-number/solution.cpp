class Solution {
public:
    // Function to convert a number n to a string in base b
string toBase(int n, int b) {
    string result = "";
    while (n > 0) {
        result = char(n % b + '0') + result;  // Get the digit in base b
        n /= b;
    }
    return result.empty() ? "0" : result;  // If the number is 0, return "0"
}

// Function to check if a string is palindromic
bool isPalindrome(const string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to check if a number n is strictly palindromic
bool isStrictlyPalindromic(int n) {
    for (int b = 2; b <= n - 2; b++) {
        string baseBRep = toBase(n, b);  // Convert n to base b
        if (!isPalindrome(baseBRep)) {   // Check if the representation is palindromic
            return false;  // If not palindromic in any base, return false
        }
    }
    return true;  // If palindromic in all bases, return true
}
};
