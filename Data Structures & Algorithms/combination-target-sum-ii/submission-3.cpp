class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void rec(vector<int>& nums, int target,int idx,vector<int>&curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(idx == n){
            return;
        }
        for(int i=idx;i<n;i++){
            if(i != idx && nums[i] == nums[i-1]){
                continue;
            }
            if(nums[i] > target){
                return;
            }else{
                curr.push_back(nums[i]);
                rec(nums,target-nums[i],i+1,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        vector<int> curr;
        rec(nums,target,0,curr);
        return ans;
    }
};
