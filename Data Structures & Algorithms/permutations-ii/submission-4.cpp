class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void rec(vector<int>& nums,vector<int>&curr,vector<bool>&used){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1] && used[i-1]){
                continue;
            }
            if(!used[i]){
                used[i] = true;
                curr.push_back(nums[i]);
                rec(nums,curr,used);
                curr.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        vector<bool> used(n,false);
        vector<int> curr;        
        rec(nums,curr,used);
        return ans;
    }
};