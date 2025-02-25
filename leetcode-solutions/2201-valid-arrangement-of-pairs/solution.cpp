class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) 
    {
        unordered_map<int,int>inDegree,outDegree;
        unordered_map<int, vector<int>> adj;
        for(int i =0;i<pairs.size();i++)
        {
            int u = pairs[i][0];
            int v = pairs[i][1];
            adj[u].push_back(v);
            inDegree[v]++;
            outDegree[u]++;
        }
        int startNode = pairs[0][0];
        for (const auto& entry : outDegree) {
            int u = entry.first;
            if (outDegree[u] - inDegree[u] == 1) {
                startNode = u;
                break;
            }
        }

        vector<int>eulerPath;
        stack<int>st;
        st.push(startNode);
        while(!st.empty())
        {
            int curr = st.top();
            if(!adj[curr].empty())
            {
                int neighbor = adj[curr].back();
                adj[curr].pop_back();
                st.push(neighbor);
            }
            else{
                eulerPath.push_back(curr);
                st.pop();
            }
        }
        reverse(eulerPath.begin(),eulerPath.end());
        vector<vector<int>>result;
        int n = eulerPath.size();
        for(int i =0;i<n-1;i++)
        {
            result.push_back({eulerPath[i],eulerPath[i+1]});
        }
        return result;
        
    }
};
