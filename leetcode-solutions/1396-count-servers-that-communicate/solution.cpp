class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int>indexRowCount(rows,0);
        vector<int>indexColCount(cols,0);

        for(int i=0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
            {
                if(grid[i][j]==1)
                {
                    indexRowCount[i]+=1;
                    indexColCount[j]+=1;
                }
                else
                continue;
            }
        }
        int result=0;
        for(int i=0;i<rows;i++)
        {
            for(int j =0;j<cols;j++)
            {
                if(grid[i][j]==1 && (indexRowCount[i]>1 || indexColCount[j]>1))
                {
                    result++;
                }
            }
        }

        return result;
        
    }
};
