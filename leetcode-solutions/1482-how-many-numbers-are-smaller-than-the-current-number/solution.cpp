class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {   map<int,int>mp;
        vector<int>answer;
        vector<int>temp=nums;
        sort(temp.begin(), temp.end());
        mp[temp[0]]=0;
        for(int i=1;i<temp.size();i++)
        {
            if(temp[i]>temp[i-1])
            {
                mp[temp[i]]=i;
            }
            else
            {
                continue;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            answer.push_back(mp[nums[i]]);
        }
        return answer;
        
    }
};
