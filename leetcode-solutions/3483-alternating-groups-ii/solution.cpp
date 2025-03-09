class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& color, int k) 
    {
        int right = 0;
        int n = color.size();
        int count = 0;
        int length= 1;
        int lastColor = color[0];
        for(int i =1;i<n+k-1;i++)
        {
            right = i%n;
            if(color[right]==lastColor)
            {
                lastColor  = color[right];
                length = 1;
                continue;
            }
            length++;
            if(length>=k)
            count++;

            lastColor = color[right];
        }
        return count;

    }
};
