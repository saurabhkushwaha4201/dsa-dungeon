class Solution {
public:
    int find(vector<int>& tops, vector<int>& bottoms,int val)
    {
        int topSteps  = 0;
        int bottomSteps = 0;
        for(int i =0;i<tops.size();i++)
        {
            if(tops[i]!=val && bottoms[i]!=val)
            {
                return -1;
            }
            else if(tops[i]!=val)
            {
                bottomSteps++;
            }
            else if(bottoms[i]!=val)
            {
                topSteps++;
            }

        }
        return min(topSteps,bottomSteps);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int minSteps = INT_MAX;
        for(int i =1;i<=6;i++)
        {
            int steps = find(tops,bottoms,i);
            if(steps!=-1)
            {
                minSteps = min(minSteps,steps);
            }
        }
        return minSteps==INT_MAX?-1:minSteps;
    }
};
