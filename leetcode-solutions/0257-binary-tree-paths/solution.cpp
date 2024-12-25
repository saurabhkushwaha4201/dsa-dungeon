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
    void dfs(TreeNode* root, vector<string>& ans, string path) {
        // Base case: If the node is NULL, just return
        if (!root) return;
        
        // Append the current node's value to the path
        path += to_string(root->val);
        
        // If it's a leaf node, push the current path to the answer
        if (!root->left && !root->right) {
            ans.push_back(path);
        } else {
            // Continue to explore left and right children, appending "->" as necessary
            path += "->";
            dfs(root->left, ans, path);
            dfs(root->right, ans, path);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, ans, "");
        return ans;
    }
};

