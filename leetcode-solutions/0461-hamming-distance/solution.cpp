class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int count=0;
        int xorResult=x^y;
        while(xorResult)
        {
            if(xorResult&1)
            {
                count++;
            }
            xorResult>>=1;
        }
        return count;
        
    }
};
