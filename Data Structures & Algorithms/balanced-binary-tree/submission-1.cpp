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
    bool ans;
    int isBalancedHelper(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        if(ans == false){
            return 0;
        }
        int l = isBalancedHelper(root->left);
        int r = isBalancedHelper(root->right);
        if(abs(r-l)>1){
            ans = false;
            return 0;
        }
        return 1+max(l,r);

    }

    bool isBalanced(TreeNode* root) {
        ans = true;
        isBalancedHelper(root);
        return ans;
    }
};
