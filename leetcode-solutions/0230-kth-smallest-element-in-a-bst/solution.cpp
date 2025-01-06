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
    // Helper function to perform in-order traversal of the tree
    void smallestKth(TreeNode* root, int& i, int k, int &ans) {
        // If the node is NULL or we've already found the kth smallest, stop the recursion
        if (root == nullptr || i >= k) {
            return;
        }

        // Recurse to the left child
        smallestKth(root->left, i, k, ans);

        // Increment the count of visited nodes
        i++;

        // If we've reached the k-th smallest element, store the result in 'ans'
        if (i == k) {
            ans = root->val;  // We assign the value of the current node to 'ans'
            return;  // Once we find the kth smallest, we return to prevent unnecessary traversal
        }

        // Recurse to the right child
        smallestKth(root->right, i, k, ans);
    }

    // Main function to find the kth smallest element
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;  // Variable to store the kth smallest value
        int i = 0;    // Counter to keep track of how many nodes have been visited

        // Call the helper function with the root node
        smallestKth(root, i, k, ans);

        // Return the result once the recursion completes
        return ans;
    }
};

