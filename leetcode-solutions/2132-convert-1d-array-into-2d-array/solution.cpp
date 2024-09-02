class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        if(m*n!=original.size())
        return {};
        vector<vector<int>> result(m,vector<int>(n));
        int index=0;
        for(int i=0;i<original.size();i++)
        {
            result[i/n][i%n]=original[i];
        }
        return result;

    }
};
