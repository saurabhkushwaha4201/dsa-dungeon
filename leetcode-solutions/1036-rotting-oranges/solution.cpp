class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        queue<pair<pair<int,int>,int>>q;
        int time= 0;
        for(int i =0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
            {
                if(grid[i][j]==2)
                {
                    // {{row,col},time}
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                
                
            }
        }

        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
       
        while(!q.empty())
        {
            int currRow = q.front().first.first;
            int currCol = q.front().first.second;
            int currTime = q.front().second;
            time  = max(time,currTime);
            q.pop();

            for(const auto &dir : directions)
            {
                int u = currRow + dir.first;
                int v = currCol + dir.second;
                if(u>=0 && u<grid.size() && v>=0 && v<grid[0].size()
                    && visited[u][v]!=2 && grid[u][v]==1 )
                    {
                        visited[u][v] = 2;
                        grid[u][v] = 2;
                        q.push({{u,v},time + 1});
                    }
            }
        }

        for(int i =0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && visited[i][j]!=1)
                {
                    return -1;
                }
            }
        }
        return time;

        
    }
};
