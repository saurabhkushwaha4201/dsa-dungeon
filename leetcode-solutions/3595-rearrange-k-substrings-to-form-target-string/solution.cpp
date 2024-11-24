class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) 
{
    int n1 = s.length(); // length of s
    int n2 = t.length();   // length of t

    int substringLength = n1/k;

    vector<string>substringOfS;
    vector<string>substringOfT;
    // store substring of s in a vector
    for(int i=0;i<n1;i+=substringLength)
        {
            substringOfS.push_back(s.substr(i,substringLength));
        }
// store substring of t in a vector
    for(int i=0;i<n2;i+=substringLength)
        {
            substringOfT.push_back(t.substr(i,substringLength));
        }

    // sort both the vector
    sort(substringOfS.begin(),substringOfS.end());
    sort(substringOfT.begin(),substringOfT.end());

    return (substringOfS==substringOfT);
        
    }
};
