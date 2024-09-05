class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        int sum_of_rolls=accumulate(rolls.begin(),rolls.end(),0);
        int sum_of_n= mean *(rolls.size()+n) - sum_of_rolls;
        if(sum_of_n>6*n||sum_of_n<n)
        return {};
        int distributedMean = sum_of_n/n;
        int mod=sum_of_n % n;
        vector<int> nElements(n,distributedMean);
        for(int i=0;i<mod;i++)
        {
            nElements[i]++;
        }
        return nElements;
    }
};
