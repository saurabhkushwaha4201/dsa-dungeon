class Solution {
public:
    bool canDistri(vector<int>& candies, long long k,int mid)
    {
        long long count = 0;
        for(int i = 0;i<candies.size();i++)
        {
            count += candies[i]/mid;

            if(count>=k)
            return true;
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int maxC = INT_MIN;
        long long totalCandies = 0;
        for(int i =0;i<candies.size();i++)
        {
            totalCandies += candies[i];
            maxC = max(maxC,candies[i]);
        }
        if(totalCandies < k)
        return 0;
        int low = 1;
        int high = maxC;
        int result = 0;
        while(low<=high)
        {
            int mid = (low + high) /2;
            if(canDistri(candies,k,mid))
            {
                result = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return result;
        
    }
};
