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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        // If both nodes are NULL, return NULL
        if (root1 == NULL && root2 == NULL)
            return NULL;

        // If one of the nodes is NULL, return the other
        if (root1 == NULL)
            return root2;
        if (root2 == NULL)
            return root1;

        // Create a new node with the sum of the two nodes' values
        TreeNode* mergedTree = new TreeNode(root1->val + root2->val);

        // Recursively merge the left and right subtrees
        mergedTree->left = mergeTrees(root1->left, root2->left);
        mergedTree->right = mergeTrees(root1->right, root2->right);

        // Return the merged tree
        return mergedTree;
    }
};

