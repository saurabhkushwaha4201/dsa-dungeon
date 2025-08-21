class Solution {
public:
    int oneDArrayCount(vector<int>&vec)
    {
        int consecutive = 0;
        int subCount = 0;
        for(int val:vec)
        {
            if(val==0)
            consecutive = 0;
            else
            consecutive +=1;

            subCount += consecutive;
        }
        return subCount;
    }
    int numSubmat(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        int result = 0;
        for(int startRow = 0;startRow<rows;startRow++)
        {
            vector<int>vec(cols,1);
            for(int endRow = startRow;endRow<rows;endRow++)
            {
                for(int col = 0;col<cols;col++)
                {
                    vec[col] = vec[col] & mat[endRow][col];
                }
                result += oneDArrayCount(vec);
            }
        }
        return result;
    }
};
