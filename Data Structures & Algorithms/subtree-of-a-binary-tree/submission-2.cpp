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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr){
            return true;
        }
        if(p == nullptr || q == nullptr){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        if(!isSameTree(p->left,q->left)){
            return false;
        }
        if(!isSameTree(p->right,q->right)){
            return false;
        }
        return true;
    }

    void isSubtreeHelper(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr){
            return ;
        }
        if(root->val == subRoot->val){
            if(isSameTree(root,subRoot)){
                ans = true;
            }
        }
        if(ans == true){
            return;
        }
        isSubtreeHelper(root->left,subRoot);
        isSubtreeHelper(root->right,subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        ans = false;
        isSubtreeHelper(root,subRoot);
        return ans;
    }
};
