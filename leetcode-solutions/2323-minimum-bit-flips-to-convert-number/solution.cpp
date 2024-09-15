class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int count=0;
        int xor_result = start^goal;
        while(xor_result!=0)
        {
            if(xor_result&1)
            {
                count++;
            }
            xor_result>>=1;
        }
        return count;

        
    }
}; 
