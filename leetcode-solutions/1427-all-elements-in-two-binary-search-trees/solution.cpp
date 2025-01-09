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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
       vector<int> result;
    stack<TreeNode*> stack1, stack2;
    TreeNode* curr1 = root1;
    TreeNode* curr2 = root2;

    while (curr1 != nullptr || curr2 != nullptr || !stack1.empty() || !stack2.empty()) {
        // Process tree 1
        while (curr1 != nullptr) {
            stack1.push(curr1);
            curr1 = curr1->left;
        }

        // Process tree 2
        while (curr2 != nullptr) {
            stack2.push(curr2);
            curr2 = curr2->left;
        }

        // If both stacks have nodes, compare them
        if (!stack1.empty() && !stack2.empty()) {
            if (stack1.top()->val < stack2.top()->val) {
                curr1 = stack1.top();
                stack1.pop();
                result.push_back(curr1->val);
                curr1 = curr1->right;
            } else {
                curr2 = stack2.top();
                stack2.pop();
                result.push_back(curr2->val);
                curr2 = curr2->right;
            }
        }
        // If only tree 1 has nodes
        else if (!stack1.empty()) {
            curr1 = stack1.top();
            stack1.pop();
            result.push_back(curr1->val);
            curr1 = curr1->right;
        }
        // If only tree 2 has nodes
        else if (!stack2.empty()) {
            curr2 = stack2.top();
            stack2.pop();
            result.push_back(curr2->val);
            curr2 = curr2->right;
        }
    }
    
    return result;
    }
};

