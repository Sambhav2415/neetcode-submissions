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
    int ans =0;
    void goodNodesHelper(TreeNode* root , int maxNo){
        if(root == nullptr){
            return;
        }
        if(root->val >= maxNo){
            ans++;
            // cout << root->val << "  ";
        }
        maxNo = max(maxNo , root->val);
        goodNodesHelper(root->left,maxNo);
        goodNodesHelper(root->right,maxNo);
    }

    int goodNodes(TreeNode* root) {
        goodNodesHelper(root , INT_MIN);
        return ans;
    }
};
