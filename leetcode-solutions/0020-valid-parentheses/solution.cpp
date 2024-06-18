class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        for(auto ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                s1.push(ch);
            } else if(ch == ')' || ch == '}' || ch == ']') {
                if(s1.empty()) return false; // More closing than opening
                char top = s1.top();
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '[')) {
                    s1.pop();
                } else {
                    return false; // Mismatched opening and closing
                }
            }
        }
        
        return s1.empty(); // Stack should be empty for valid expression
    
    }
};
