class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i]);
    }

    void unionByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;  // attach y_parent to x_parent
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;  // attach x_parent to y_parent
        } else {
            parent[y_parent] = x_parent;  // arbitrarily attach y_parent to x_parent
            rank[x_parent] += 1;           // increase rank of the new root
        }
    }
    bool isSimilar(string s1,string s2)
    {
        int diff = 0;
        for(int i =0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
            {
                diff++;
            }
        }
        return diff==2 || diff==0;
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i =0;i<n;i++)
        {
            parent[i]= i;
        }
        int groupCount = n;
        for(int i =0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(isSimilar(strs[i],strs[j]) && find(i)!=find(j))
                {
                    unionByRank(i,j);
                    groupCount--;
                }
            }
        }
        return groupCount;
        
    }
};
