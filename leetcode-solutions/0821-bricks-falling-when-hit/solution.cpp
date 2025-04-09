
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
    int m, n;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    
    int getIndex(int i,int j,int col)
    {
        return i*col + j;
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        m = grid.size();
        n = grid[0].size();
        Dsu dsu(m * n + 1);
        int top =m *n; // for virtual node
        // Copy of the original grid so we can apply hits
        vector<vector<int>> modified = grid;

        // Step 1: Apply all hits (remove bricks from copy)
        for (auto& hit : hits) {
            int row = hit[0], col = hit[1];
            if (modified[row][col] == 1)
                modified[row][col] = 0;
        }

        for(int i =0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(modified[i][j]==1)
                {
                    if(i==0)
                    {
                        dsu.unite(getIndex(0,j,n),top);
                    }
                     
                    for(auto &dir:directions)
                    {
                        int nRow = i + dir.first;
                        int nCol = j+ dir.second;
                        if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && modified[nRow][nCol]==1)
                        {
                            dsu.unite(getIndex(i,j,n),getIndex(nRow,nCol,n));
                        }
                    }

                }
                
                
            }
        }

        int hitSize = hits.size();
        vector<int> result(hitSize);

        // Step 3: Process hits in reverse
        for (int i = hitSize - 1; i >= 0; --i) {
            int row = hits[i][0], col = hits[i][1];

            // If no brick existed originally, nothing falls
            if (grid[row][col] == 0) {
                result[i] = 0;
                continue;
            }
            else
            {
                int oldSize = dsu.size(top);
                // Restore the brick
                modified[row][col] = 1;
                if(row==0)
                {
                    dsu.unite(getIndex(row,col,n),top);
                }
                for(auto &dir:directions)
                {
                    int nRow = row + dir.first;
                    int nCol = col+ dir.second;
                    if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && modified[nRow][nCol]==1)
                    {
                        dsu.unite(getIndex(row,col,n),getIndex(nRow,nCol,n));
                    }
                }

                int newSize = dsu.size(top);
                result[i] = max(0,newSize- oldSize - 1);

            }
            
        }

        return result;
    }
};

