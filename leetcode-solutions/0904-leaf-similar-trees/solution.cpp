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
    // Helper function to check if a node is a leaf node
    bool isLeaf(TreeNode* root)
    {
        // A node is a leaf if it is not null and has no left or right children
        return (root != nullptr && root->left == nullptr && root->right == nullptr);
    }

    // Recursive function to collect leaf node values into a vector
    void addNode(TreeNode* root, vector<int>& nums)
    {
        // Base case: if the node is null, return
        if (root == nullptr)
            return;

        // Traverse the left subtree
        addNode(root->left, nums);

        // If the current node is a leaf, add its value to the vector
        if (isLeaf(root))
        {
            nums.push_back(root->val);
        }

        // Traverse the right subtree
        addNode(root->right, nums);
    }

    // Main function to check if two binary trees are leaf-similar
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        // Vectors to store the leaf node values for both trees
        vector<int> temp1, temp2;
        
        // Populate the leaf node values from both trees
        addNode(root1, temp1);
        addNode(root2, temp2);
        
        // Compare the leaf sequences; if they are equal, return true
        return temp1 == temp2;
    }
};

