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
    TreeNode* insertIntoBST(TreeNode* root, int value) {
        TreeNode* temp = root;
        if(root == nullptr){
            return new TreeNode(value);
        }
        while(true){
            if(temp->val > value){
                if(temp->left == nullptr){
                    temp->left = new TreeNode(value);
                    break;
                }else{
                    temp = temp->left;
                }
            }else{
                if(temp->right == nullptr){
                    temp->right = new TreeNode(value);
                    break;
                }else{
                    temp = temp->right;
                }
            }
        }
        return root;
    }
};