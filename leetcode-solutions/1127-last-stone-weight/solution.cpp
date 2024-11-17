class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++)
        pq.push(stones[i]);
        while(pq.size()>1)
        {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            // if(stone1 == stone2)
            // pq.pop();
            if( stone1 > stone2)
            {
                stone1= stone1-stone2;
                pq.push(stone1);
            }
            
        }
        if(pq.empty())
        return 0;
        else
        return pq.top();
        
    }
};
