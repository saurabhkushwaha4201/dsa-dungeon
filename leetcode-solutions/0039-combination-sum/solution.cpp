class Solution {
public:
    void solve(vector<int>&candidates,int target,int index,int sum,vector<int>temp,vector<vector<int>>&result)
    {
        if(sum==target)
        {
            result.push_back(temp);
            return;
        }
        if(sum>target || index>=candidates.size())
        return;
        temp.push_back(candidates[index]);
        solve(candidates,target,index,sum+candidates[index],temp,result);
        temp.pop_back();
        solve(candidates,target,index+1,sum,temp,result);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int>temp;
        vector<vector<int>>result;
        solve(candidates,target,0,0,temp,result);
        return result;
        
    }
};
