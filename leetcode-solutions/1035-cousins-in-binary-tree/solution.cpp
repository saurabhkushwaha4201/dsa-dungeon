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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int childCount = 0;
        while(!q.empty())
        {
            
            int size= q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                int parentCount=0;
                if(temp->left!=NULL)
                {
                    if(temp->left->val==x || temp->left->val==y)
                    {
                        parentCount++;
                        childCount++;
                    }
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    if(temp->right->val==x || temp->right->val==y)
                    {
                        parentCount++;
                        childCount++;
                    }
                    q.push(temp->right);
                }
                if(parentCount==2)
                return false;
            }
            if(childCount==2)
            return true;
            if(childCount==1)
            return false;
        }
        return false;        
    }
};
