class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,int>mpp;
        int n = x.size();
        for(int i = 0;i<n;i++)
        {
            // new element for map
            if(mpp.find(x[i])==mpp.end())
            {
                mpp[x[i]] = y[i];
            }
            else // alreadẏpresent then take max 
            {
                mpp[x[i]] = max(mpp[x[i]],y[i]);
            }
        }

        if(mpp.size()<3)
        return -1;

        vector<int>maxValues;
        for(auto it:mpp)
        {
            maxValues.push_back(it.second);
        }
        sort(maxValues.rbegin(),maxValues.rend());
        return maxValues[0] + maxValues[1] + maxValues[2];
        
    }
};
