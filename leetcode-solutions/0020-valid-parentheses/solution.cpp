class Solution {
public:
    bool isValid(string s) {
    // Create a stack to keep track of opening brackets
    stack<char> st;

    // Iterate over each character in the string
    for (int i = 0; i < s.length(); i++) {
        // If the character is an opening bracket, push it onto the stack
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } 
        // If the character is a closing bracket
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            // Check if the stack is empty (no corresponding opening bracket)
            if (st.empty())
                return false; // Invalid because there's no matching opening bracket
            
            // Check if the top of the stack matches the closing bracket
            if ((s[i] == ')' && st.top() == '(') ||
                (s[i] == ']' && st.top() == '[') ||
                (s[i] == '}' && st.top() == '{')) {
                st.pop(); // If it matches, pop the opening bracket from the stack
            } else {
                return false; // Invalid because the brackets do not match
            }
        }
        else
        return false;
    }
    // After processing all characters, check if the stack is empty
    return st.empty(); // If empty, all brackets matched; otherwise, invalid
}

};
