class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        unordered_map<int,int> rankCount;
        vector<int>temp;
        temp=arr;
        sort(temp.begin(),temp.end());
        int rank=1;
        for(int i=0;i<temp.size();i++)
        {
            if(i>0&& temp[i]>temp[i-1])
            {
                rank++;
            }
            rankCount[temp[i]] = rank;
        }
        for(int i=0;i<arr.size();i++)
        {
            arr[i] = rankCount[arr[i]];
        }
        return arr;    
    }
};
