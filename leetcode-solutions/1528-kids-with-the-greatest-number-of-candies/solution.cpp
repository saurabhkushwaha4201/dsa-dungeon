class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool>answer;
        int maxi=INT_MIN;
        for(int i:candies)
        {
            maxi=max(maxi,i);
        }
        for(int i:candies)
        {
            if(i + extraCandies >= maxi)
            {
                answer.push_back(true);
            }
            else
            {
                answer.push_back(false);
            }
        }
        return answer;
        
    }
};
