class Solution {
public:
    int m,n;
    bool validPath(int i,int j)
    {
        if(i<0 || i>=m || j<0 || j>=n)
        {
            return false;
        }
        return true;
    }
    int solve(int startRow,int startCol,int nonObstacle,vector<vector<int>>& grid)
    {
        if(!validPath(startRow,startCol) || grid[startRow][startCol]==-1)
        {
            return 0;
        }

        if(grid[startRow][startCol]==2)
        {
            if(nonObstacle==0)
            {
                return 1;
            }
            else
            return 0;
        }

        
        int temp = grid[startRow][startCol];
        grid[startRow][startCol] = -1;
        int left = solve(startRow,startCol-1,nonObstacle-1,grid);
        int right = solve(startRow,startCol+1,nonObstacle-1,grid);
        int down = solve(startRow+1,startCol,nonObstacle-1,grid);
        int up = solve(startRow-1,startCol,nonObstacle-1,grid);
        grid[startRow][startCol] = temp;
        return left + right + down + up;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();


        int startRow = 0;
        int startCol = 0;
        int nonObstacle = 1;
        for(int i =0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    startRow = i;
                    startCol = j;
                }
                if(grid[i][j]==0)
                {
                    nonObstacle++;
                }
            }
        }

        return solve(startRow,startCol,nonObstacle,grid);
        
    }
};
