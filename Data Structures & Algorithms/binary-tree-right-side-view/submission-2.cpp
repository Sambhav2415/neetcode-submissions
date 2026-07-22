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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*> qu;
        vector<int> ans;
        qu.push(root);
        while(!qu.empty()){
            int n = qu.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = qu.front();
                qu.pop();
                if(i == n-1){
                    ans.push_back(temp->val);
                }
                if(temp->left != nullptr){
                    qu.push(temp->left);
                }
                if(temp->right != nullptr){
                    qu.push(temp->right);
                }
            }
        }
        return ans;
    }
};
