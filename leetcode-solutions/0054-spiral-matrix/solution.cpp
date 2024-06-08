class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> result;
    if (matrix.empty())
     return result;

    int nRows = matrix.size();
    int mCols = matrix[0].size();

    int top = 0, bottom = nRows - 1;
    int left = 0, right = mCols - 1;

    while (top <= bottom && left <= right) 
    {
        // Traverse from left to right along the top row
        for (int col = left; col <= right; col++) 
        {
            result.push_back(matrix[top][col]);
        }
        top++; // Move the top boundary down

        // Traverse from top to bottom along the right column
        for (int row = top; row <= bottom; row++) 
        {
            result.push_back(matrix[row][right]);
        }
        right--; // Move the right boundary left

        // Traverse from right to left along the bottom row
        if (top <= bottom) 
        { // Ensure we are still within bounds
            for (int col = right; col >= left; col--) 
            {
                result.push_back(matrix[bottom][col]);
            }
            bottom--; // Move the bottom boundary up
        }

        // Traverse from bottom to top along the left column
        if (left <= right) 
        { // Ensure we are still within bounds
            for (int row = bottom; row >= top; row--) 
            {
                result.push_back(matrix[row][left]);
            }
            left++; // Move the left boundary right
        }
    }

    return result;
    }
};
