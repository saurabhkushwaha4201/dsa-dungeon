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
    // This map will store the depth of each node by its value
    unordered_map<int, int> mpp;
    // This will store the maximum depth of the tree
    int maxHeight;

    // Helper function to calculate the depth of each node
    void height(TreeNode* root, int depth) {
        if (root == NULL) {
            return; // Base case: if the node is NULL, return
        }
        
        // Update the maximum depth encountered so far
        maxHeight = max(maxHeight, depth);
        
        // Store the depth of the current node in the map
        mpp[root->val] = depth;
        
        // Recursively explore the left and right children, increasing depth by 1
        height(root->left, depth + 1);
        height(root->right, depth + 1);
    }

    // Helper function to find the Lowest Common Ancestor (LCA) of the deepest leaves
    TreeNode* lca(TreeNode* root) {
        if (root == NULL || mpp[root->val] == maxHeight) {
            // If the current node is NULL or is one of the deepest leaves, return this node
            return root;
        }
        
        // Recursively search for LCA in the left and right subtrees
        TreeNode* left = lca(root->left);
        TreeNode* right = lca(root->right);
        
        // If LCA is found in both subtrees, the current node is the LCA
        if (left != NULL && right != NULL) {
            return root;
        }
        
        // If only one subtree has the LCA, return that
        return left != NULL ? left : right;
    }

    // Main function to find the LCA of the deepest leaves
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // Step 1: Calculate the maximum depth of the tree and store depths of all nodes
        height(root, 0);

        // Step 2: Find the LCA of the deepest leaves and return it
        return lca(root);
    }
};

