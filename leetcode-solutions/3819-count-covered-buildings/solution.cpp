class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int>rowMin(n+1,INT_MAX),rowMax(n+1,INT_MIN);
        vector<int>colMin(n+1,INT_MAX),colMax(n+1,INT_MIN);

        for(auto x:buildings)
            {
                int a = x[0];
                int b = x[1];
                rowMin[a] = min(rowMin[a],b);
                rowMax[a] = max(rowMax[a],b);
                colMin[b] = min(colMin[b],a);
                colMax[b] = max(colMax[b],a);
            }
        int count = 0;
        for(auto x:buildings)
            {
                int a = x[0];
                int b = x[1];
                if(rowMin[a]<b && rowMax[a]>b && colMin[b]<a && colMax[b]>a)
                {
                    count++;
                }
            }
        return count;
    }
};
