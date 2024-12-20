/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Step 1: Define a map to store vertical order of nodes.
        // The map will have:
        // - key: horizontal distance (hd)
        // - value: a map of (level -> set of node values at that level)
        map<int, map<int, multiset<int>>> verticalMap;

        // Step 2: Create a result vector to hold the final vertical traversal.
        vector<vector<int>> result;

        // Step 3: Create a queue to perform BFS (Breadth-First Search)
        // Each element in the queue will store a pair:
        // - Node pointer
        // - Pair containing horizontal distance (hd) and level of the node
        queue<pair<TreeNode*, pair<int, int>>> bfsQueue;
        
        // Step 4: Start BFS with the root node, at hd = 0 and level = 0
        bfsQueue.push({root, {0, 0}});

        while (!bfsQueue.empty()) {
            auto frontNode = bfsQueue.front();
            bfsQueue.pop();

            // Step 5: Extract the node, horizontal distance, and level from the queue
            TreeNode* currentNode = frontNode.first;
            int horizontalDistance = frontNode.second.first;
            int currentLevel = frontNode.second.second;

            // Step 6: Insert the node's value into the map at the correct position
            // We use a multiset to handle duplicate values at the same level.
            verticalMap[horizontalDistance][currentLevel].insert(currentNode->val);

            // Step 7: Enqueue the left child with an updated horizontal distance and level
            if (currentNode->left) {
                bfsQueue.push({currentNode->left, {horizontalDistance - 1, currentLevel + 1}});
            }

            // Step 8: Enqueue the right child with an updated horizontal distance and level
            if (currentNode->right) {
                bfsQueue.push({currentNode->right, {horizontalDistance + 1, currentLevel + 1}});
            }
        }

        // Step 9: Build the result from the map
        for (auto& horizontalPair : verticalMap) {
            vector<int> column;
            // For each vertical line (each horizontal distance), extract the node values
            for (auto& levelPair : horizontalPair.second) {
                column.insert(column.end(), levelPair.second.begin(), levelPair.second.end());
            }
            // Add the extracted column to the result
            result.push_back(column);
        }

        // Step 10: Return the final vertical traversal
        return result;
    }
};

