class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int count = 0;
        int n = weight.size();
        
      
        int i = 0;
        while(i<n-1)
        {
            int maxi = weight[i];
            int j = i+1;
            bool found  = false;

            while(j<n)
            {
                maxi = max(maxi,weight[j]);

                if(maxi>weight[j])
                {
                    count++;
                    i = j+1;
                    found = true;
                    break;
                }
                j++;
            }
            if(!found)
            break;
        }
        return count;
    }
};
