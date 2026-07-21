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
    int ans = INT_MIN;

    int mPS(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = mPS(root->left);
        int right = mPS(root->right);

        // ans = max(ans,max(left,right));
        // ans = max(ans , max(left+root->val,right+root->val));
        // ans = max(ans , left+root->val+right);
        ans = max(ans,root->val + max(0,left)+max(0,right));
        return (root->val+max(0 , max(left,right)));
    }

    int maxPathSum(TreeNode* root) {
        mPS(root);
        return ans; 
    }
};
