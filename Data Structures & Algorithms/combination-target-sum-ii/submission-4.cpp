class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void dp(vector<int>& nums,int idx,vector<int>&curr,int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(idx == n){
            return;
        }

        for(int i=idx;i<n;i++){
            if(i != idx && nums[i-1] == nums[i]){
                continue;
            }
            if(nums[i] <= target){
                curr.push_back(nums[i]);
                dp(nums,i+1,curr,target-nums[i]);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        vector<int> curr;
        dp(nums,0,curr,target);
        return ans;
    }
};
