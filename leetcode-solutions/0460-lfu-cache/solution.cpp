#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int val;
    int freq;
};

class LFUCache {
public:
    int cap;
    map<int, list<Node>> freq; // freq -> list of nodes (most-recent at front)
    unordered_map<int, list<Node>::iterator> mpp; // key -> iterator to node in its freq list

    LFUCache(int capacity) {
        cap = capacity;
    }

    void makeMostFrequentlyUsed(int key){
        auto it = mpp[key];             // iterator to Node in its current list
        Node node = *it;                // copy current node
        int f = node.freq;
        // erase the node from current frequency list
        freq[f].erase(it);
        if (freq[f].empty()) {
            freq.erase(f);             // remove bucket if empty
        }
        // increase frequency and insert into front of next bucket
        node.freq = f + 1;
        freq[node.freq].push_front(node);
        mpp[key] = freq[node.freq].begin();
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        auto it = mpp[key];
        int value = it->val;
        makeMostFrequentlyUsed(key);
        return value;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        // key already exists -> update value and bump freq
        if (mpp.find(key) != mpp.end()) {
            auto it = mpp[key];
            it->val = value;           // update value in-place
            makeMostFrequentlyUsed(key);
            return;
        }

        // if room available, just insert with freq = 1
        if ((int)mpp.size() < cap) {
            Node node{key, value, 1};
            freq[1].push_front(node);
            mpp[key] = freq[1].begin();
            return;
        }

        // capacity full -> evict least frequently used
        // freq.begin() is the smallest frequency bucket because map is ordered
        auto &evictList = freq.begin()->second;   // IMPORTANT: reference, not copy
        int keyToDelete = evictList.back().key;   // least recently used in that freq (back)
        evictList.pop_back();                     // remove from list
        if (evictList.empty()) {
            freq.erase(freq.begin()->first);      // erase bucket if empty
        }
        // remove from mpp
        mpp.erase(keyToDelete);

        // insert new node with freq = 1
        Node newNode{key, value, 1};
        freq[1].push_front(newNode);
        mpp[key] = freq[1].begin();
    }
};

