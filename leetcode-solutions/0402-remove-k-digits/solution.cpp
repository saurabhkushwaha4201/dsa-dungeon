#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for (char ch : num) {
            // While there are still digits to remove and the current digit is less than the top of the stack
            while (!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        
        // If we still have digits to remove, remove them from the top
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the result from the stack
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        // Reverse the result to get the correct order
        reverse(res.begin(), res.end());

        // Remove leading zeros
        while (res.size() > 1 && res[0] == '0') {
            res.erase(res.begin());
        }

        return res.empty() ? "0" : res; // Return "0" if result is empty
    }
};

