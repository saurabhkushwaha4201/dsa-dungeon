class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
        int operations = 0;
        
        while(!pq.empty())
        {
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();
            if(num1 >= k  && num2 >= k)
            break;
            long long num = min(num1,num2) * 2 + max(num1,num2);
            pq.push(num);
            operations++;
            
        }
        return operations;
    }
};
