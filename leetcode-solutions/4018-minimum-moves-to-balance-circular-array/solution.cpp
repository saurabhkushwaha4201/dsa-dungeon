class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        long long total = 0;
        int neg = -1;

        for (int i = 0; i < n; i++) {
            total += balance[i];
            if (balance[i] < 0){
                neg = i;
            } 
        }
        if(total < 0){
            return -1;// not possible 
        }
        if(neg == -1){
            return 0;//no need
        }
        long long need = -balance[neg];
        vector<pair<int,long long>>available;
        for (int i = 0; i < n; i++) {
            if (i == neg || balance[i] <= 0){
                continue;
            } 
            int dist = abs(i - neg);
            dist = min(dist, n - dist); // circular distance
            available.push_back({dist, balance[i]});
        }
        sort(available.begin(), available.end());

        long long ans = 0;
        for (auto &[dist, supply] : available) {
            if (need == 0) break;
            long long take = min(need, supply);
            ans += take * dist;
            need -= take;
        }

        return (need == 0 ? ans : -1);
    }
};
