class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(),
                  ::tolower);
        string word= "";
        unordered_map<string, int> mpp;
        for (char ch : paragraph) {
            if (isalpha(ch)) {
                word += ch;
            } else if(!word.empty()) {
                mpp[word]++;
                word = "";
            } 
        }
        if (!word.empty()) {
            mpp[word]++;
            
        }
        for(int i =0;i<banned.size();i++)
        {
            mpp[banned[i]]= -1;
        }
        string result;
        int maxi = INT_MIN;

        for (auto& it : mpp) {
            if (it.second > maxi) {
                maxi = it.second;
                result = it.first;
            }
        }

        return result;
    }
};
