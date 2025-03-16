class Solution {
public:
    typedef long long LL;
    bool isPossible(vector<int>ranks,LL mid, int cars)
    {
        LL carsFixed = 0;
        for(int i = 0;i<ranks.size();i++)
        {
            carsFixed += sqrt(mid/ranks[i]);
        }
        return carsFixed>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) 
    {
        LL low = 1;
        LL maxC= *max_element(ranks.begin(),ranks.end());
        LL high = 1LL*cars*cars*maxC;
        LL result = -1;
        while(low<=high)
        {
            LL mid = (low + high)/2;
            if(isPossible(ranks,mid,cars))
            {
                result = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return result;
        
    }
};
