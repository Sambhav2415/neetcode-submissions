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
    int diam = 0;

    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        int k = 1+max(l,r);
        diam = max(diam,l+r);
        return k;
    }

    int diameterOfBinaryTree(TreeNode* root) {
       int k = maxDepth(root);
       return diam;
    }
};
