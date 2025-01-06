class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.size();
        vector<int>ans(n,0);
        int cummValue  = 0;
        int cummValueSum = 0;
        for(int i=0;i<n;i++)
        {
            ans[i] = cummValueSum;
            if(boxes[i]=='0')
            cummValue += 0;
            else
            cummValue += 1;

            cummValueSum += cummValue;

        }

        cummValue =0;
        cummValueSum =0;
        for(int i=n-1;i>=0;i--)
        {
            ans[i] += cummValueSum;
            if(boxes[i]=='0')
            cummValue += 0;
            else
            cummValue += 1;

            cummValueSum += cummValue;
        }
        return ans;
    }
};
