class Solution {
public:
    static constexpr int MOD = 1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& A) {
        int m = A.size(), n = A[0].size();
        // must start at S and end at E
        if (A[m-1][n-1] != 'S' || A[0][0] != 'E')
            return {0,0};

        // dpScore[i][j] = max score to reach (i,j) from S
        // dpCnt  [i][j] = count of ways achieving dpScore[i][j]
        vector dpScore(m, vector<int>(n, INT_MIN));
        vector dpCnt  (m, vector<int>(n, 0));

        // Seed the start
        dpScore[m-1][n-1] = 0;
        dpCnt  [m-1][n-1] = 1;

        // Directions reversed: from S → E means we look “up/left/up-left”
        int dirs[3][2] = {{-1,0},{0,-1},{-1,-1}};

        // Sweep row by row from bottom-right back to top-left
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (A[i][j]=='X' || (i==m-1 && j==n-1)) 
                    continue;

                int best = INT_MIN, ways = 0;
                // collect from any neighbor that can move “into” (i,j)
                for (auto &d: dirs) {
                    int pi = i - d[0], pj = j - d[1]; 
                    // pi,pj = predecessor coords (down, right, down-right)
                    if (pi<0 ||pj<0||pi>=m||pj>=n) continue;
                    if (dpScore[pi][pj]==INT_MIN)    continue;

                    int sc = dpScore[pi][pj];
                    if (sc > best) {
                        best = sc;
                        ways = dpCnt[pi][pj];
                    }
                    else if (sc == best) {
                        ways = (ways + dpCnt[pi][pj]) % MOD;
                    }
                }

                if (best==INT_MIN) 
                    continue;   // unreachable

                // add this cell’s digit (E and S both add 0)
                int add = isdigit(A[i][j]) ? A[i][j]-'0' : 0;
                dpScore[i][j] = best + add;
                dpCnt  [i][j] = ways;
            }
        }

        int score = dpScore[0][0];
        int cnt   = dpCnt  [0][0];
        if (score < 0) 
            return {0,0};
        return {score, cnt};
    }
};

