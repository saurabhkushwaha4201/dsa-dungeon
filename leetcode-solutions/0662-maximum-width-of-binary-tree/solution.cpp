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
    int widthOfBinaryTree(TreeNode* root) 
    {
        // If the tree is empty, the width is 0
        if(root == NULL)
            return 0;

        int width = 0;
        
        // Queue to perform level-order traversal with node and its position (use long long for positions)
        queue<pair<TreeNode*, long long>> q;
        
        // Push the root node with position 0
        q.push({root, 0});

        while(!q.empty())
        {
            // Get the current level size
            int size = q.size();
            
            // Get the position of the first node in this level (min position)
            long long mini = q.front().second;
            
            long long start, end;
            
            // Process all nodes at the current level
            for(int i = 0; i < size; i++)
            {
                // Get the current node and its position
                long long currId = q.front().second - mini;
                TreeNode* currNode = q.front().first;
                q.pop();

                // If it's the first node in the level, set start
                if(i == 0)
                    start = currId;
                
                // If it's the last node in the level, set end
                if(i == size - 1)
                    end = currId;

                // Push left and right children to the queue with updated positions
                if(currNode->left)
                    q.push({currNode->left, currId * 2 + 1});
                if(currNode->right)
                    q.push({currNode->right, currId * 2 + 2});
            }

            // Update the maximum width (end - start + 1) for the current level
            width = max(width, (int)(end - start + 1));
        }
        
        return width;
    }
};

