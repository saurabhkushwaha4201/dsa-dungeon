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
    // Helper function to check if two trees are identical
    bool isIdentical(TreeNode* root, TreeNode* subroot) {
        // Base case: both nodes are NULL, so the trees are identical
        if (root == NULL && subroot == NULL) return true;
        
        // If one of the nodes is NULL and the other isn't, trees are not identical
        if (root == NULL || subroot == NULL) return false;
        
        // Recursively check if the left subtrees and right subtrees are identical
        return (root->val == subroot->val) && 
               (isIdentical(root->left, subroot->left)) && 
               (isIdentical(root->right, subroot->right));
    }

    // Main function to check if a subtree exists in the given tree
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base case: if the root tree is NULL, the subtree cannot exist
        if (root == NULL) return false;
        
        // If the current node matches the subtree, check if the trees are identical
        if (isIdentical(root, subRoot)) return true;
        
        // Otherwise, recursively check both the left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
