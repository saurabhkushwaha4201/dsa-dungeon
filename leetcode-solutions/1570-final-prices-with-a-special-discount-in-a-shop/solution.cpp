class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        stack<int> st;  // Stack to store prices as we traverse the array from right to left
        
        // Traverse the array from right to left
        for(int i = prices.size() - 1; i >= 0; i--) {
            
            // While the stack is not empty and the top of the stack is greater than the current price
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();  // Pop elements from the stack that are larger than the current price
            }

            int temp = prices[i];  // Store the current price in a temporary variable

            // If there is still an element in the stack, it is the next smaller element
            if (!st.empty()) {
                prices[i] -= st.top();  // Apply the discount (subtract next smaller element from the current price)
            }

            // Push the current price onto the stack for future comparisons
            st.push(temp);
        }
        
        return prices;  // Return the modified array with final prices
    }
};

