class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>prev(grid[0]);
        for(int i = 1;i<n;i++)
        {
            vector<int>curr(n);
            int min1 = INT_MAX,min2 = INT_MAX;
            int minIndex = -1;
            for(int j = 0;j<n;j++)
            {
                int v = prev[j];
                if (v < min1) {
                    min2   = min1;
                    min1   = v;
                    minIndex = j;
                }
                else if(prev[j]<min2)
                {
                    min2 = prev[j];
                }
            }
            for(int j = 0;j<n;j++)
            {
                int bestPrev = (j == minIndex) ? min2 : min1;
                if (bestPrev == INT_MAX)
                    curr[j] = INT_MAX;
                else
                    curr[j] = grid[i][j] + bestPrev;

            }
            prev = curr;
        }
        return *min_element(prev.begin(),prev.end());

        
    }
};
