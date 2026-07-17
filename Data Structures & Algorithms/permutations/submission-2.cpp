class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> ans;
    int n;
    void rec(vector<int>& nums,vector<int>&curr){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                curr.push_back(nums[i]);
                vis[i] = true;
                rec(nums,curr);
                curr.pop_back();
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        vis.assign(n,false);
        rec(nums,curr);
        return ans;
    }
};
