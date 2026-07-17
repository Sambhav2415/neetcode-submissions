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
            if(vis[i]){
                continue;
            }
            if(i > 0 && nums[i] == nums[i-1] && !vis[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            vis[i] = true;
            rec(nums,curr);
            curr.pop_back();
            vis[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        sort(nums.begin(),nums.end());
        vis.assign(n,false);
        rec(nums,curr);
        return ans;
    }
};