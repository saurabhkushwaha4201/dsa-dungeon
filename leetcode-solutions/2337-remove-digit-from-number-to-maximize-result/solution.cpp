class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.length();
        string ans = "";
        for(int i =0;i<n;i++)
        {

            if(number[i]==digit)
            {
                string temp = number;
                temp.erase(temp.begin()+i);
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};
