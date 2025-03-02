class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int left  = 0;
        int right = 0;
        int n = fruits.size();
        int maxFruits = INT_MIN;
        int count = 0;
        unordered_map<int,int>mpp;
        while(right<n)
        {
            mpp[fruits[right]]++;
            while(mpp.size()>2)
            {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0) 
                {
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            maxFruits = max(maxFruits,right-left+1);
            right++;

        }
        return maxFruits;
        
    }
};
