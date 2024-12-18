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
    bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == NULL) 
        return false; // Base case: If the root is NULL, no path can exist.

    // If it's a leaf node and the target sum equals the node's value, return true.
    if (root->left == NULL && root->right == NULL) 
        return root->val == targetSum;

    // Recursively check the left and right subtrees, passing the reduced targetSum
    int remainingSum = targetSum - root->val; // Reduce the target sum by the current node's value
    return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
}

};
