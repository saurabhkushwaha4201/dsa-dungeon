class Solution {
public:
    unordered_map<int,vector<int>>adj;
    unordered_map<int,int>bobMap;
    int aliceIncome;
    bool dfsBob(int curr, int time,vector<bool>&visited)
    {
        visited[curr] = true;
        bobMap[curr] = time;
        if(curr==0)
        return true;
        for(auto &neighbor : adj[curr])
        {
            if(!visited[neighbor])
            {
                if(dfsBob(neighbor,time+1,visited))
                {
                    return true;
                }
            }
        }
        bobMap.erase(curr);
        return false;
    }
    void dfsAlice(int curr, int time, int income, vector<bool>&visited,vector<int>&amount)
    {
        visited[curr] = true;
        if(bobMap.find(curr)==bobMap.end() || time < bobMap[curr])
        {
            income += amount[curr];
        }
        else if(time==bobMap[curr])
        {
            income += (amount[curr])/2;
        }
        if(adj[curr].size()==1 && curr !=0)
        {
            aliceIncome = max(aliceIncome,income);
        }
        for(int &neighbor:adj[curr])
        {
            if(!visited[neighbor])
            {
                dfsAlice(neighbor,time+1,income,visited,amount);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
    {
        int n = amount.size();
        aliceIncome = INT_MIN;
        for(int i = 0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int time = 0;
        vector<bool>visited(n,false);
        dfsBob(bob,time,visited);
        int income = 0;
        visited.assign(n,false);
        dfsAlice(0,0,income,visited,amount);
        return aliceIncome;
    }
};
