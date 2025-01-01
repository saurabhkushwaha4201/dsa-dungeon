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
    TreeNode* constructTree(vector<int>& postorderTraversal, 
                            int& currentPostorderIndex, 
                            unordered_map<int, int>& inorderIndexMap, 
                            int inorderStart, 
                            int inorderEnd) {
        // If the start index exceeds the end index, no subtree can be built, return NULL.
        if (inorderStart > inorderEnd)
            return nullptr;

        // The current root value is the value at currentPostorderIndex in the postorder traversal.
        int rootValue = postorderTraversal[currentPostorderIndex--];

        // Create the root node for this subtree.
        TreeNode* rootNode = new TreeNode(rootValue);

        // Find the index of the root value in the inorder traversal.
        int inorderIndex = inorderIndexMap[rootValue];

        // Recursively build the right subtree. Right subtree is built first because postorder traversal
        // processes right subtree before left subtree.
        rootNode->right = constructTree(postorderTraversal, currentPostorderIndex, inorderIndexMap, 
                                        inorderIndex + 1, inorderEnd);

        // Recursively build the left subtree.
        rootNode->left = constructTree(postorderTraversal, currentPostorderIndex, inorderIndexMap, 
                                       inorderStart, inorderIndex - 1);

        // Return the constructed subtree's root node.
        return rootNode;
    }
    
    TreeNode* buildTree(vector<int>& inorderTraversal, vector<int>& postorderTraversal) {
        // Create a map to store the index of each value in the inorder traversal for O(1) lookups.
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorderTraversal.size(); ++i) {
            inorderIndexMap[inorderTraversal[i]] = i;
        }

        // Start the postorder index from the last element since postorder traversal ends with the root.
        int currentPostorderIndex = postorderTraversal.size() - 1;

        // Build and return the binary tree.
        return constructTree(postorderTraversal, currentPostorderIndex, inorderIndexMap, 
                             0, inorderTraversal.size() - 1);
    }
};
