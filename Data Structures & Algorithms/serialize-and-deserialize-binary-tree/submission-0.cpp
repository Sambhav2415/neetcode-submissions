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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "N";
        }
        queue<TreeNode*> q;
        string ans = "";
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == nullptr){
                ans += "N,";
                continue;
            }
            ans += to_string(temp->val) + ",";
            q.push(temp->left);
            q.push(temp->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "N")
            return nullptr;

        vector<string> nodes;
        string temp = "";

        // Split the string using ','
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(nodes[i] != "N"){
                temp->left = new TreeNode(stoi(nodes[i]));
                q.push(temp->left);
            }
            i++;

            if(nodes[i] != "N"){
                temp->right = new TreeNode(stoi(nodes[i]));
                q.push(temp->right);
            }
            i++;
        }
        return root;
    }
};
