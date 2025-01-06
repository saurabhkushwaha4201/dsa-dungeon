class Solution {
public:
    // Function to find the minimum value node in a subtree (leftmost node)
    TreeNode* minValue(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;

        if (root->val == key) {
            // Case 1: No child
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // Case 2: One child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            // Find the in-order successor (smallest node in the right subtree)
            TreeNode* successor = minValue(root->right);
            // Replace the value of the current node with the successor's value
            root->val = successor->val;
            // Delete the in-order successor from the right subtree
            root->right = deleteNode(root->right, successor->val);
        }
        // If the key to delete is smaller, go to the left subtree
        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        // If the key to delete is larger, go to the right subtree
        else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};

