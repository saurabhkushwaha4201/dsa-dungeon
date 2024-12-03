class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        string result = "";
        int i=0;
        int j=0;
        int k=0;
        while( i<s.length() )
        {
            j=i;
            if(k<spaces.size() && j==spaces[k] ) 
            {
                result +=" ";
                k++;
            }
            result += s[i];
            i++;
        }
        return result;
        
    }
};
