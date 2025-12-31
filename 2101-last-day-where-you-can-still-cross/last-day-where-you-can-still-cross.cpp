class Dsu {
private:
    vector<int> parent;
    vector<int> sz; // Size of each component

public:
    // Constructor
    Dsu(int n) {
        parent.resize(n);
        sz.resize(n, 1); // Every node starts with size 1
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Initially, each node is its own parent
        }
    }

    // Find with path compression
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union by size
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return; // Already in same component

        if (sz[px] < sz[py]) {
            swap(px, py); // Always attach smaller to larger
        }

        parent[py] = px;
        sz[px] += sz[py];
    }

    // Size of component
    int size(int x) {
        return sz[find(x)];
    }
};
class Solution {
public:
    int getIndex(int i,int j,int col)
    {
        return i*col + j;
    }
    vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        vector<vector<int>>modified(row,vector<int>(col,1));
        Dsu dsu(row*col+2);
        int top = row*col;
        int bottom = row*col+1;
        for(int i = cells.size()-1;i>=0;i--)
        {
            int r = cells[i][0]-1;
            int c= cells[i][1]-1;
            modified[r][c] = 0;
            if(r==0)
            {
                dsu.unite(top,getIndex(r,c,col));
            }
            if(r==row-1)
            {
                dsu.unite(bottom,getIndex(r,c,col));
            }
            for(auto &dir:directions)
            {
                int nRow = r + dir.first;
                int nCol = c + dir.second;
                if(nRow>=0 && nRow<row && nCol>=0 && nCol<col && modified[nRow][nCol]==0)
                {
                    dsu.unite(getIndex(r,c,col),getIndex(nRow,nCol,col));
                }
            }

            if(dsu.find(top)==dsu.find(bottom))
            {
                return i;
            }
        }
        return 0;
        
    }
};