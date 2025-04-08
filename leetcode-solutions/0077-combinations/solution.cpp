class Solution {
public:
    void solve(int n, int k,int index, vector<vector<int>>&result,vector<int>&temp)
    {
        if(temp.size()==k)
        {
            result.push_back(temp);
            return;
        }
        if(index>n)
        return;

        temp.push_back(index);
        solve(n,k,index+1,result,temp);
        temp.pop_back();
        solve(n,k,index+1,result,temp);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int>temp;
        solve(n,k,1,result,temp);
        return result;
    }
};
