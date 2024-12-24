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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
         queue<TreeNode*>
            q; // Create a queue to store nodes for level order traversal
        q.push(
            root); // Push the root node into the queue to start the traversal
        q.push(nullptr); // Mark the end of the first level with a nullptr

        vector<vector<int>>
            ans; // Vector to store the result (list of values for each level)
        vector<int>
            level; // Temporary vector to store values of the current level
        if (root == NULL)
            return ans;

        while (!q.empty()) { // Loop until the queue is empty (i.e., all levels
                             // have been processed)
            TreeNode* node = q.front(); // Get the front node from the queue
            q.pop();                    // Pop the front node from the queue

            if (node == nullptr) { // If the node is nullptr, it marks the end
                                   // of a level
                ans.push_back(
                    level);    // Add the current level's values to the result
                level.clear(); // Clear the level for the next level's values
                if (!q.empty()) { // If there are more nodes to process, mark
                                  // the next level's end with nullptr
                    q.push(nullptr);
                }
            } else {
                level.push_back(node->val); // Add the current node's value to
                                            // the level list
                if (node->left != nullptr)
                    q.push(
                        node->left); // If left child exists, add to the queue
                if (node->right != nullptr)
                    q.push(
                        node->right); // If right child exists, add to the queue
            }

        }
        reverse(ans.begin(),ans.end());
        return ans; // Return the list of values for each level of the tree
        
    }
};
