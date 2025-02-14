class Solution {
public:
    vector<int>size;
    vector<int>parent;
    int find(int i)
    {
        if(i==parent[i])
        return i;
        return parent[i] = find(parent[i]);
    }
    void unionBysize(int x,int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent==y_parent)
        {
            return;
        }
        if(size[x_parent] > size[y_parent])
        {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
        else if (size[x_parent]< size[y_parent])
        {
            parent[x_parent]= y_parent;
            size[y_parent] += size[x_parent];
        }
        else
        {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        parent.resize(n);
        size.resize(n,1);
        int edgeExtra = 0;
        for(int i =0;i<n;i++)
        {
            parent[i] = i;
        }
        for(auto &it:connections)
        {
           int u = it[0];
           int v = it[1];

           if(find(u)==find(v))
           {
            edgeExtra++;
           }
           else
           {
            unionBysize(u,v);
           } 
        }
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            if(parent[i]==i)
            count++;
        }
        // We need `count - 1` extra edges to connect all components
        int ans = count - 1;

        // If we have enough extra edges to connect all components, return the result
        if (edgeExtra >= ans) {
            return ans;
        }

        return -1; // Not enough edges to connect all components

    }
};
