/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if (!root) return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr == NULL) {
                ans.append("#,");
            } else {
                ans.append(to_string(curr->val) + ",");
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if (data.empty()) return NULL;
        
        // Use stringstream to process the serialized data
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        
        // Create the root node
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            // Process the left child
            getline(ss, str, ',');
            if (str == "#") {
                curr->left = NULL;
            } else {
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }
            
            // Process the right child
            getline(ss, str, ',');
            if (str == "#") {
                curr->right = NULL;
            } else {
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
