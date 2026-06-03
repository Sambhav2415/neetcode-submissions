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
    TreeNode* lca = nullptr;
    bool toFind = true;
    void lCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!toFind){
            return;
        }
        if(root == nullptr){
            return ;
        }
        if((root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val)){
            lca = root;
            toFind = false;
            return;
        }else if(root->val >=p->val && root->val>=q->val){
            lca = root;
            if(root->val == p->val || root->val == q->val){
                toFind = false;
                return;
            }
            lCA(root->left,p,q);
        }else if (root->val <=p->val && root->val<=q->val){
            lca = root;
            if(root->val == p->val || root->val == q->val){
                toFind = false;
                return;
            }
            lCA(root->right,p,q);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lCA(root,p,q);
        return lca;
    }
};
