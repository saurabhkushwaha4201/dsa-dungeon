class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        vector<int>ans(A.size());
        map<int,int>mpp;
        int count=0;
        for(int i=0;i<A.size();i++)
        {
            
            mpp[A[i]]++;
            if(mpp[A[i]]==2)
            count++;

            mpp[B[i]]++;
            if(mpp[B[i]]==2)
            count++;

            ans[i] = count;
        }
        return ans;
    }
};
