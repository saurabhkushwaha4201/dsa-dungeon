class Solution {
public:
    bool canAliceWin(int n) {
        bool alicewin = false;
        if (n < 10)
            return false;
        if (n == 10)
            return true;
        int stonesToRemove = 10;
        while (n > 0) {
            n -= stonesToRemove;
            stonesToRemove--;
            if (n < stonesToRemove)
                return true; // Alice wins
            if (n == stonesToRemove)
                return false; // Bob wins
            // stonesToRemove--;
            n -= stonesToRemove;
            stonesToRemove--;
            if (n < stonesToRemove)
                return false; // Bob wins
            if (n == stonesToRemove)
                return true; // Alice wins
        }
        return false; // This line should never be reached
    }
};
