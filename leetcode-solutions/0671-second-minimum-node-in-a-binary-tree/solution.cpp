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
    
    long long int secondMinValue = LLONG_MAX;
    void dfs(TreeNode* root,int minValue)
    {
        if(root==NULL)
        return;
        // If the current node's value is greater than min_val but less than second_min_val, update it

        if(root->val>minValue && root->val<secondMinValue)
        {
            secondMinValue = root->val;
        }
       
            dfs(root->left, minValue);
            dfs(root->right, minValue);
        
    }
    int findSecondMinimumValue(TreeNode* root) 
    {
        int minValue = root->val;
        dfs(root,minValue);
        return secondMinValue == LLONG_MAX ? -1 : secondMinValue;
    }
};
