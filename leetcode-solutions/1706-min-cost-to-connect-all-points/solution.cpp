class Solution {
public:
    typedef pair<int,int>P;
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,0});

        vector<bool>inMst(n,false);
        int sum = 0;
        while(!pq.empty())
        {
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if(inMst[node]==true)
            continue;
            sum += weight;
            inMst[node] = true;
            for(int i = 0;i<n;i++)
            {
                if(!inMst[i])
                {
                    int dist = abs(points[node][0]-points[i][0]) + abs(points[node][1] - points[i][1]);
                    pq.push({dist,i});
                }
            }
        }
        return sum;;


        
    }
};
