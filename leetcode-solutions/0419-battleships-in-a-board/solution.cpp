class Solution {
public:
    int countBattleships(vector<vector<char>>& board) 
    {
        int count = 0;
        for(int i =0;i<board.size();i++)
        {
            for(int j =0;j<board[0].size();j++)
            {
                
                if (board[i][j] == 'X') {
                // Check if it's the start of a battleship
                if ((i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.')) {
                    count++;
                }
            }
            }
        }
        
       
        return count;
    }
};
