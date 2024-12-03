class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case: if the node is null, return null
        if (root == nullptr) {
            return nullptr;
        }

        // Swap the left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        // Return the root after inversion
        return root;
    }
};
