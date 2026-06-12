class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums,vector<bool>& used,vector<int>& count){
        if(count.size()==nums.size()){
            ans.push_back(count);
            return;
        }
        for(int i=0;i<used.size();i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            count.push_back(nums[i]);
            solve(nums,used,count);
            used[i] = false;
            count.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> count;
        vector<bool> used(nums.size(),false);
        solve(nums,used,count);
        return ans;
    }
};
