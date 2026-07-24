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

        if(nums[idx] <= target){
            curr.push_back(nums[idx]);
            dp(nums,idx,curr,target-nums[idx]);
            curr.pop_back();
        }
        
        dp(nums,idx+1,curr,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> curr;
        dp(nums,0,curr,target);
        return ans;
    }
};
