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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans; // This will store the final right side view of the tree.
        
        if(root == NULL) // If the root is NULL (empty tree), return an empty vector.
            return ans;

        queue<TreeNode*> q; // A queue is used for level-order traversal (BFS).
        q.push(root); // Start with the root node.

        while(!q.empty()) // Process all levels of the tree
        {
            int size = q.size(); // Get the number of nodes at the current level.
            
            // Loop through all the nodes in the current level
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front(); // Get the front element of the queue (current node).
                q.pop(); // Remove the front element from the queue.

                // Check if we are at the last node of the current level (rightmost node).
                if(i == size - 1)
                    ans.push_back(curr->val); // Add the value of the rightmost node to the result.

                // If the current node has a left child, add it to the queue for the next level.
                if(curr->left)
                    q.push(curr->left);
                
                // If the current node has a right child, add it to the queue for the next level.
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return ans; // Return the final vector containing the right side view of the tree.
    }
};

