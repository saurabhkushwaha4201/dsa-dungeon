class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minRow = INT_MAX, minCol = INT_MAX, maxRow = INT_MIN, maxCol = INT_MIN;

        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    minRow = min(minRow,i);
                    minCol = min(minCol,j);
                    maxRow = max(maxRow,i);
                    maxCol = max(maxCol,j);
                }
            }
        }
        return (maxRow-minRow + 1) * (maxCol - minCol+1);
    }
};
