class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        int n = s.length();  // Length of the string s
        vector<int> difference(n, 0);  // Difference array to keep track of shifts

        // Process each shift operation in the 'shifts' vector
        for (auto &query : shifts) {
            int left = query[0];  // Starting index of the range (inclusive)
            int right = query[1]; // Ending index of the range (inclusive)
            int direction = query[2];  // Direction of the shift (0 = left, 1 = right)
            int x;  // This will store the actual shift value (either +1 or -1)

            // Determine whether the shift is to the left (0) or right (1)
            if (direction == 0)
                x = -1;  // Left shift
            else
                x = 1;   // Right shift

            // Apply the shift to the difference array
            difference[left] += x;  // Increment the shift at the left index
            if (right + 1 < n)       // Check if there’s a valid index beyond 'right'
                difference[right + 1] -= x;  // Decrement at the index just after the right boundary
        }

        // Now calculate the cumulative sum of shifts, starting from index 1 to avoid accessing negative index
        for (int i = 1; i < n; i++) {
            difference[i] += difference[i - 1];  // Accumulate the shift values into each position
        }
        
        // Apply the cumulative shifts to the original string 's'
        for (int i = 0; i < n; i++) {
            int shift = (difference[i] % 26);  // Modulo 26 ensures the shifts wrap around the alphabet

            if (shift < 0)
                shift += 26;  // If the shift is negative, adjust it to ensure it stays within the range [0, 25]

            // Update the character at position 'i' by applying the calculated shift
            s[i] = ((s[i] - 'a') + shift) % 26 + 'a';  // Shift the character and wrap it within 'a' to 'z'
        }

        return s;  // Return the modified string after all shifts have been applied
    }
};

