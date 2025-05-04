class Solution {
public:
    vector<vector<int>>solve(int n)
    {
        if(n==0)
        {
            return {{0}};
        }

        auto smallQUad = solve(n-1);
        int s = 1<<(n-1);
        int quadSize = s*s;

        vector<vector<int>>result(2*s,vector<int>(2*s));

        for(int i =0;i<s;i++)
            {
                for(int j = 0;j<s;j++)
                    {
                        int temp  = smallQUad[i][j];
                        result[i][j+s] = temp;

                        result[i+s][j+s] = temp + quadSize;

                        result[i+s][j] = temp + 2*quadSize;

                        result[i][j] = temp + 3*quadSize;
                    }
            }
        return result;
    }
    vector<vector<int>> specialGrid(int N) {
        return solve(N);
    }
};
