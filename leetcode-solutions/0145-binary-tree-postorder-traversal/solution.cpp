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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        if(!root)return ans;

        stack<TreeNode*>st;
        TreeNode* lastVisited = NULL;
        TreeNode* node = root;
        
        while(!st.empty() || node!=NULL )
        {
            if(node!=NULL)
            {
                st.push(node);
                node= node->left;
            }
            else
            {
                TreeNode* peekNode = st.top();
                if(peekNode->right!=NULL && lastVisited!=peekNode->right)
                {
                    node= peekNode->right;
                }
                else
                {
                    ans.push_back(peekNode->val);
                    st.pop();
                    lastVisited = peekNode;
                }
            }
        }
        return ans;

        
    }
};
