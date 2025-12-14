class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int countVowels(const string& word) {
        int cnt = 0;
        for (char c : word) {
            if (isVowel(c)) {
                cnt++;
            }
        }
        return cnt;
    }
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        stringstream ss(s);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
        int firstVowelCount = countVowels(words[0]);
        for (int i = 1; i < words.size(); i++) {
            if (countVowels(words[i]) == firstVowelCount) {
                reverse(words[i].begin(), words[i].end());
            }
        }
        string result;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0)
                result += ' ';
            result += words[i];
        }

        return result;
    }
};
