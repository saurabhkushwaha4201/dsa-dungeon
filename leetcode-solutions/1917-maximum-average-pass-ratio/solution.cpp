class Solution {
public:
    typedef pair<double,pair<int,int>>P;    // {classRation,{pass,total}}
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<P>pq;
        int n = classes.size();
        auto calculateGain = [](int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) - (double)passes / totalStudents;
        };

        for(int i = 0;i<classes.size();i++)
        {
            
            pq.push({calculateGain(classes[i][0],classes[i][1]),{classes[i][0],classes[i][1]}});
        }
        
        while(extraStudents--)
        {
            auto it = pq.top();
            pq.pop();
            int currPass = it.second.first;
            int currTotal = it.second.second;

            int newPass = currPass + 1;
            int newTotal = currTotal + 1;

            double delta = calculateGain(newPass,newTotal);
            pq.push({delta, {newPass, newTotal}});

        }
        double result = 0;
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            result +=(it.second.first*1.0)/(it.second.second);
        }
        return result/n;
    }
};
