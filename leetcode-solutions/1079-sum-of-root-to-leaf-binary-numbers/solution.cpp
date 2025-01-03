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
    void dfs(TreeNode* root,int& sum,int currentValue)
    {
        if(root==NULL)
        return;
        currentValue  = currentValue*2 + root->val;
        if(root->left==NULL && root->right==NULL)
        {
            sum+= currentValue;
            return;
        }
        dfs(root->left,sum,currentValue);
        dfs(root->right,sum,currentValue);

    }
    int sumRootToLeaf(TreeNode* root) 
    {
        int sum = 0;
        
        dfs(root,sum,0);
        return sum;
        
    }
};
