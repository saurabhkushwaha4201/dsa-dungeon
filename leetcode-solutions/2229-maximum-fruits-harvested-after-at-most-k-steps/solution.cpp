class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> position(n), prefixSum(n);

        for(int i = 0;i<fruits.size();i++)
        {
            position[i] = fruits[i][0];

            prefixSum[i] = fruits[i][1] + (i>0 ? prefixSum[i-1] : 0);
        }
        int maxFruits = 0;
        for(int d = 0;d<=k/2;d++)
        {

            // case 1 -> move d steps to left then come to startpos
            int remain = k - 2*d;
            int i = startPos - d;
            int j = startPos + remain;

            int left = lower_bound(position.begin(),position.end(),i) - position.begin();
            int right = upper_bound(position.begin(),position.end(),j) - position.begin()-1;
            if(left<=right)
            {
                int total = prefixSum[right] - (left>0 ? prefixSum[left-1] : 0);
                maxFruits = max(maxFruits,total);
            }

            // case 2 -> move d steps to right then come to startPos
            i = startPos - remain;
            j = startPos + d;
            left = lower_bound(position.begin(),position.end(),i) - position.begin();
            right = upper_bound(position.begin(),position.end(),j) - position.begin()-1;
            if(left<=right)
            {
                int total = prefixSum[right] - (left>0 ? prefixSum[left-1] : 0);
                maxFruits = max(maxFruits,total);
            }
        }

        return maxFruits;
    }
};
