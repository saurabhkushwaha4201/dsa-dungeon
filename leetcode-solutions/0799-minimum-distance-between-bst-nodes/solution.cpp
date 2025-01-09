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
    int mini = INT_MAX;
    void inorder(TreeNode*root,int& preVal)
    {
        if(root==NULL)
        return;
        inorder(root->left,preVal);
        if(preVal!=-1)
        {
            mini = min(mini,(root->val-preVal));
        }
        preVal = root->val;
        inorder(root->right,preVal);
    }
    int minDiffInBST(TreeNode* root) 
    {
        int preVal = -1;
        inorder(root,preVal);
        return mini;

        
    }
};
