class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int>leftClosetR(n,-1);
        vector<int>rightClosetL(n,-1);
        string ans(n,' ');
        // find left closet right for each domino
        for(int i =0;i<n;i++)
        {
            if(dominoes[i]=='R')
            {
                leftClosetR[i] = i;
            }
            else if(dominoes[i]=='L')
            {
                leftClosetR[i] = -1;
            }
            else if(i > 0 && leftClosetR[i-1] != -1)
            {
                leftClosetR[i] = leftClosetR[i-1];
            }
        }
        // right closet left
        for(int i = n-1;i>=0;i--)
        {
            if(dominoes[i]=='L')
            {
                rightClosetL[i] = i;
            }
            else if(dominoes[i]=='R')
            {
                rightClosetL[i]=-1;
            }

            else if(i < n-1 && rightClosetL[i+1] != -1)
            {
                rightClosetL[i] = rightClosetL[i+1];
            }
        
        }

        for(int i = 0;i<n;i++)
        {
            int d1 = abs(i-leftClosetR[i]);
            int d2 = abs(i-rightClosetL[i]);
            
            if(leftClosetR[i]==-1 &&  rightClosetL[i]==-1)
            {
                ans[i] = '.';
            }
            else if(leftClosetR[i]==-1 && rightClosetL[i]!=-1)
            {
                ans[i] = 'L';
            }
            else if(leftClosetR[i]!=-1 && rightClosetL[i]==-1)
            {
                ans[i] = 'R';
            }
            else if(d1<d2)
            {
                ans[i] = 'R';
            }
            else if(d2<d1)
            {
                ans[i] = 'L';
            }
            else if(d1==d2)
            ans[i] = '.';
            
        }
        return ans;

    }
};
