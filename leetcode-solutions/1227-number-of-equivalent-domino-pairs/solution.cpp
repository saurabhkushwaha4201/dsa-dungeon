class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int>mpp;
        int n = dominoes.size();
        int count = 0;
        for(int i =0;i<n;i++)
        {
            int a= dominoes[i][0];
            int b = dominoes[i][1];
            int key;
            if(a>b)
            {
                key = b*10 + a;
            }
            else
            {
                key = a*10 + b;
            }

            count += mpp[key];
            mpp[key]++;
        }
        return count;
    }
};
