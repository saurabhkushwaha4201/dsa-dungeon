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
    bool equationsPossible(vector<string>& equations) 
    {
        parent.resize(26);
        rank.resize(26,0);
        for(int i =0;i<26;i++)
        {
            parent[i] = i;
        }

        for(int i =0;i<equations.size();i++)
        {
            int first = equations[i][0] - 'a';
            int second = equations[i][3]-'a';
            if(equations[i][1]=='=')
            {
                unionByRank(first,second);
            }
            
        }
        for(int i =0;i<equations.size();i++)
        {
            int first = equations[i][0] - 'a';
            int second = equations[i][3]-'a';
            if(equations[i][1]=='!')
            {
                int first_parent = find(first);
                int second_parent = find(second);
                if(first_parent==second_parent)
                return false;
            }
        }
        return true;
        
    }
};
