class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int rows = isWater.size();
        int cols = isWater[0].size();
        vector<vector<int>>result(rows,vector<int>(cols,-1));
        queue<pair<int,int>>q;
        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i = 0;i<rows;i++)
        {
            for(int j =0;j<cols;j++)
            {
                if(isWater[i][j]==1)
                {
                    result[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto & dir:directions)
            {
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols && result[nrow][ncol] == -1)
                {
                    result[nrow][ncol] = result[row][col] +1;
                    q.push({nrow,ncol});
                }
            }
        }
        return result;
        
    }
};
