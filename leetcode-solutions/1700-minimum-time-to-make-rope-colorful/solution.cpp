class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int maxTime = neededTime[0];
        int minTime = 0;
        int n = colors.size();
        for(int i = 1;i<n;i++){
            if(colors[i]==colors[i-1]){
                minTime+=min(maxTime,neededTime[i]);
                maxTime = max(maxTime,neededTime[i]);
            }
            else{
                maxTime = neededTime[i];
            }
        }
        return minTime;
    }
};
