class Solution {
public:
    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>&grid,int u, int v, vector<vector<bool>>&visited)
    {
        visited[u][v] = true;

        for(auto &dir:directions)
        {
            int newrow = u + dir.first;
            int newcol = v + dir.second;
            if(newrow >=0 && newrow < grid.size() && newcol >= 0 && newcol < grid[0].size()
                 && visited[newrow][newcol]==false )
            {
                if(grid[newrow][newcol]==0)
                dfs(grid,newrow,newcol,visited);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));

        for(int i =0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
            {
                if(i==0 || i==(rows-1) || j==0 || j==(cols-1) )
                {
                    if(grid[i][j]==0)
                    dfs(grid,i,j,visited);
                }
            }
        }
        int count = 0;
        for(int i =0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
            {
                if(!visited[i][j] && grid[i][j]==0)
                {
                    dfs(grid,i,j,visited);
                    count++;
                }
            }
        }
        return count;
        
    }
};
