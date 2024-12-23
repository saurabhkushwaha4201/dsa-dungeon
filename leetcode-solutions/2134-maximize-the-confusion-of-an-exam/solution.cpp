class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) 
    {
        int right = 0;
        int left=0;
        map<char,int>mpp;
        int maxLength = INT_MIN;
        int maxFre = 0;
        while(right<s.length())
        {
            mpp[s[right]]++;
            maxFre = max(maxFre,mpp[s[right]]);
            if ( (right-left+1 ) - maxFre >k)
            {
                mpp[s[left]]--;
                left++;
            }
            maxLength = max(maxLength,right-left+1);
            right++;
        }
        return maxLength;
        
    }
};
