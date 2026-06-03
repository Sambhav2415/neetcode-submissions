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
    bool height = true;
    int maxDepth(TreeNode* root) {
        if(height == false){
            return 0;
        }
        if(root == nullptr){
            return 0;
        }
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if(abs(l-r)>1){
            height = false;
        }
        return 1+max(l,r);
    }

    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return height;
    }
};
