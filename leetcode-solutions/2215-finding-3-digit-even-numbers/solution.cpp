class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>result;
        vector<int>freq(10);
        for(int num:digits)
        freq[num]++;

        for(int i = 1;i<=9;i++)
        {
            if(freq[i]==0)
            continue;
            freq[i]--;
            for(int j = 0;j<=9;j++)
            {
                if(freq[j]==0)
                continue;
                freq[j]--;
                for(int k = 0;k<=8;k+=2)
                {
                    if(freq[k]==0)
                    continue;
                    freq[k]--;

                    int num = (i*100) + (j*10) + (k*1);
                    result.push_back(num);
                    freq[k]++;
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return result;
    }
};
