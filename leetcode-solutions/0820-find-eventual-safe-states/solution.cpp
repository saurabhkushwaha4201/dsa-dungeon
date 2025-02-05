class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int v = graph.size();
        vector<vector<int>>adj(v);
        vector<int>inDegree(v,0);
        for(int i =0;i<v;i++)
        {
            for(auto & v : graph[i])
            {
                adj[v].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int>q;
        for(int i =0;i<v;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<bool>safe(v,false);
        vector<int>result;
        while(!q.empty())
        {
            int u = q.front();
            safe[u] = true;
            q.pop();
            for(auto &v:adj[u])
            {
                inDegree[v]--;
                if(inDegree[v]==0)
                q.push(v);
            }
        }
        for(int i =0;i<v;i++)
        {
            if(safe[i])
            result.push_back(i);
        }
        return result;
        
    }
};
