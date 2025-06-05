#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findparent(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = findparent(parent[x]);
    }

    void unionBySmallest(int x, int y) {
        int px = findparent(x);
        int py = findparent(y);
        if (px == py) return;
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        for (int i = 0; i < s1.length(); i++) {
            ds.unionBySmallest(s1[i] - 'a', s2[i] - 'a');
        }

        string ans = "";
        for (char c : baseStr) {
            int ch = ds.findparent(c - 'a');
            ans += (char)(ch + 'a');
        }
        return ans;
    }
};

