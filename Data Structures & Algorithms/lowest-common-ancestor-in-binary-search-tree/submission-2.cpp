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
    TreeNode* lc = nullptr;
    bool toFind = true;
    void lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return;
        }
        if(!toFind){
            return;
        }
        int rv = root->val;
        int pv = p->val;
        int qv = q->val;
        if((rv >= pv && rv <= qv) || (rv <= pv && rv >= qv)){
            lc = root;
            toFind = false;
            return;
        }else if(rv <= pv && rv <= qv){
            lc = root;
            if(rv == pv || rv == qv){
                toFind = false;
                return;
            }
            lca(root->right,p,q);
        }else{
            lc = root;
            if(rv == pv || rv == qv){
                toFind = false;
                return;
            }
            lca(root->left,p,q);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root,p,q);
        return lc;
    }
};
