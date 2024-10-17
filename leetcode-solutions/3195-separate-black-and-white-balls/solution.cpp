class Solution {
public:
    long long minimumSteps(string s) 
    {
        int end=s.length()-1;
        long long ans=0;
        int zero_count=0;
        while(end>=0)
        {
            if(s[end]=='0')
            {
                zero_count++;
            }
            else
            {
                ans += zero_count;
            }
            end--;
        }
        return ans;
    }
};
