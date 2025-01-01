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
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
    
    void dfs(TreeNode* root, vector<vector<string>>& ans, int row, int col, int height) {
        if (!root) return;
        ans[row][col] = to_string(root->val);
        
        // Process left subtree if it exists
        if (root->left) {
            int leftCol = col - pow(2, height - row - 1);
            dfs(root->left, ans, row + 1, leftCol, height);
        }
        
        // Process right subtree if it exists
        if (root->right) {
            int rightCol = col + pow(2, height - row - 1);
            dfs(root->right, ans, row + 1, rightCol, height);
        }
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        if (root == NULL)
            return {};
        
        int h = height(root)-1;
        int rows = h+1; // height of the tree
        int cols = pow(2, h+1) - 1; // width of the tree
        
        // Create a 2D vector to hold the output, initialized with empty strings
        vector<vector<string>> ans(rows, vector<string>(cols, ""));
        
        // Start DFS from the root at row 0, col (cols-1)/2
        dfs(root, ans, 0, (cols - 1) / 2, h);
        
        return ans;
    }
};

