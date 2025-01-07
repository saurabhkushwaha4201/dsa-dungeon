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
    // Helper function to build the BST from preorder traversal
    TreeNode* buildTree(vector<int>& preorder, int& preIndex, int upperBound) {
        // Base case: if we've processed all nodes or the current node value exceeds the upper bound
        if (preIndex == preorder.size() || preorder[preIndex] > upperBound)
            return NULL;
        
        // Create the current node with the value from preorder[preIndex]
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        // Recursively build the left subtree
        // Left subtree must have values smaller than the current root's value (upper bound is root->val)
        root->left = buildTree(preorder, preIndex, root->val);
        
        // Recursively build the right subtree
        // Right subtree must have values greater than the current root's value (upper bound is passed unchanged)
        root->right = buildTree(preorder, preIndex, upperBound);
        
        // Return the current root node
        return root;
    }
    
    // Main function to generate the BST from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preIndex = 0;  // Initialize the index to start from the beginning of the preorder array
        return buildTree(preorder, preIndex, INT_MAX);  // Call the helper function with a large upper bound (INT_MAX)
    }
};

