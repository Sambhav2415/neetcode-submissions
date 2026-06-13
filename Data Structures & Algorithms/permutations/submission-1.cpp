class Solution {
public:
    vector<vector<int>> ans;
    int n ;

    void solve(vector<int>& nums,vector<bool>& used,vector<int> count){
        if(count.size()==n){
            ans.push_back(count);
            return;
        }
        for(int i=0;i<n;i++){
            if(used[i]) continue;
            used[i] = true;
            count.push_back(nums[i]);
            solve(nums,used,count);
            used[i] = false;
            count.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<bool> used(n,false);
        solve(nums,used,{});
        return ans;
    }
};
