class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        
        int i = 0;
        while(i<n && s[i]=='a'){
            i++;
        }
        if(i>=n){
            s[n-1] = 'z';
        }
        while(i<n && s[i]!='a'){
            s[i] = s[i]-1;
            i++;
        }
        return s;
    }
};
