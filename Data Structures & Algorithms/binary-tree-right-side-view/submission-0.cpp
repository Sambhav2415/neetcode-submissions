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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int , TreeNode*>> q;
        q.push({0,root});
        while(!q.empty()){
            auto[i,x] = q.front();
            q.pop();
            if(x == nullptr){
                continue;
            }else{
                cout << x->val;
                q.push({i+1,x->left});
                q.push({i+1,x->right});
            }
        }
        return {{}};
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<=n-1;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                if(i==n-1){
                    ans.push_back(node->val);
                }           
            }
        }
        return ans;
    }
};
