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
    int gis(TreeNode* root){
        while(root->left != nullptr){
            root = root->left;
        }
        return root->val;
    }

    TreeNode* del(TreeNode* root, int key){
        if(root == nullptr){
            return nullptr;
        }
        if(root->val > key){
            root->left = del(root->left,key);
        }else if(root->val < key){
            root->right = del(root->right,key);
        }else{
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }else if(root->left == nullptr){
                TreeNode*temp = root->right;
                delete root;
                return temp;
            }else if(root->right == nullptr){
                TreeNode*temp = root->left;
                delete root;
                return temp;
            }else{
                int succ = gis(root->right);
                root->val = succ;
                root->right = del(root->right,succ);
            }
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return del(root,key);
    }
};