class Solution {
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        unordered_map<int, int> cardCount;
    int left = 0, minLength = INT_MAX;

    for (int right = 0; right < cards.size(); ++right) {
        cardCount[cards[right]]++;

        while (cardCount[cards[right]] > 1) {
            minLength = min(minLength, right - left + 1);
            cardCount[cards[left]]--;
            left++;
        }
    }

    return minLength == INT_MAX ? -1 : minLength;
    
        
    }
};
