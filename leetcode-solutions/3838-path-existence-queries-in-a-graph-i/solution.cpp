class DSU {
public:
    vector<int> parent, sz;
    DSU(int n): parent(n), sz(n,1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x]==x ? x : parent[x]=find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a==b) return false;
        // union by size
        if (sz[a] < sz[b]) std::swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);
        for(int i =0;i<n-1;i++)
            {
                if(abs(nums[i]-nums[i+1])<=maxDiff)
                {
                    dsu.unite(i,i+1);
                }
            }
        vector<bool>ans;
        for(auto q:queries)
            {
                int a = q[0];
                int b = q[1];
                ans.push_back(dsu.find(a)==dsu.find(b));
            }
        return ans;
    }
};
