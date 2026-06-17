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
    TreeNode* gis(TreeNode* root){
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode1(TreeNode* root,int key){
        if(root == nullptr){
            return nullptr;
        }
        if(key < root->val){
            root->left = deleteNode1(root->left,key);
        }else if(key > root->val){
            root->right = deleteNode1(root->right,key);
        }else{
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }else if(root->left == nullptr || root->right == nullptr){
                return root->left == nullptr?root->right : root->left;
            }else{
                TreeNode* iS = gis(root->right);
                root->val = iS->val;
                root->right = deleteNode1(root->right , iS->val);
            }
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNode1(root,key);
    }
};