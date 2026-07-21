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
// {canBuy,can'tBuy} 
class Solution {
public:
    pair<int,int> rob3(TreeNode* root){
        if(root == nullptr){
            return {0,0};
        }
        pair<int,int> l = rob3(root->left);
        pair<int,int> r = rob3(root->right);

        int canBuy = root->val + l.second+r.second;
        int canNotBuy = max(l.first,l.second)+max(r.first,r.second);
        return {canBuy,canNotBuy};
    }

    int rob(TreeNode* root) {
        pair<int,int> ans = rob3(root);
        return max(ans.first,ans.second);
    }
};