
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        vector<string> answer;
        unordered_map<string, int> word_count;
        string word = "";

        // Process the first sentence
        for (char ch : s1)
        {
            if (ch == ' ')
            {
                word_count[word]++;
                word = "";    
            }
            else
            {
                word += ch;
            }
        }
        if (!word.empty()) 
        {
            word_count[word]++;
        }

        // Process the second sentence
        word = "";
        for (char ch : s2)
        {
            if (ch == ' ')
            {
                word_count[word]++;
                word = "";
            }
            else
            {
                word += ch;
            }
        }
        if (!word.empty()) 
        {
            word_count[word]++;
        }

        // Collect uncommon words
        for ( auto i : word_count)
        {
            if (i.second == 1)
            {
                answer.push_back(i.first);
            }
        }

        return answer;
    }
};

