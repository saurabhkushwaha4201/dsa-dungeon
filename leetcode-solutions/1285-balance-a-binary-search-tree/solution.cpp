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
    TreeNode* buildTree(vector<int>&nums,int start,int end)
    {
        if(start>end)
        return NULL;
        int mid = (start+end)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = buildTree(nums,start,mid-1);
        newNode->right=buildTree(nums,mid+1,end);
        return newNode;
    }
    void inorder(TreeNode*root,vector<int>&result)
    {
        if(root==NULL)
        return ;
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int>result;
        inorder(root,result);
        int start = 0;
        int end = result.size()-1;
        return buildTree(result,start,end);
    }
};
