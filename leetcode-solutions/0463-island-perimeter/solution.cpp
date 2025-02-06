class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i , int j , int rows,int cols, int&perimeter)
    {
        if(i< 0 || i>= rows  || j>= cols || j< 0 || grid[i][j]==0)
        {
            perimeter++;
            return ;
        }
        if(grid[i][j]==-1)
        return;

        grid[i][j] = -1;

        dfs(grid,i-1,j,rows,cols,perimeter);
        dfs(grid,i+1,j,rows,cols,perimeter);
        dfs(grid,i,j-1,rows,cols,perimeter);
        dfs(grid,i,j+1,rows,cols,perimeter);
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        int perimeter = 0;

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,m,n,perimeter);
                    return perimeter;
                }
            }
        }
        return -1;
        
    }
};
