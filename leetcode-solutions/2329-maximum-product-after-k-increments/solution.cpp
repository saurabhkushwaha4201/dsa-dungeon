class Solution {
public:

    int maximumProduct(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        while(k--)
        {
            int mini = pq.top();
            pq.pop();
            mini = mini + 1;
            pq.push(mini);
        }
        long long multiply = 1;
        while(!pq.empty())
        {
            multiply = (multiply * pq.top()) % 1000000007;

            pq.pop();
        }
        return (int)(multiply % 1000000007);
        
    }
};
