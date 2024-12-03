class Solution {
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int maxCount = INT_MIN;
        for(int i=0;i<sentences.size();i++)
        {
            int count=0;
            for(int j=0;j<sentences[i].size();j++)
            {
                if(sentences[i][j]==' ')
                count++;
            }
            maxCount = max (maxCount,count);
        }
        return (maxCount+1);
        
    }
};
