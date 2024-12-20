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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size=q.size();
            vector<TreeNode*>levelElements;
            for(int i=0;i<size;i++)
            {
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
                levelElements.push_back(temp);
            }
            if(level%2!=0)
            {
                int i=0;
                int j=levelElements.size()-1;
                while(i<=j)
                {
                    swap(levelElements[i]->val,levelElements[j]->val);
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }
};
