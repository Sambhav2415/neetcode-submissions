class Solution {
public:
    int n;
    int rec(vector<int>& nums, int target,int idx,vector<vector<int>> &dp){
        if(idx == n){
            if(target == 0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[idx][target+1000]!=-1){
            return dp[idx][target+1000];
        }
        int add = rec(nums,target-nums[idx],idx+1,dp);
        int subt = rec(nums,target+nums[idx],idx+1,dp);
        return dp[idx][target+1000]=add+subt;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2001,-1));
        return rec(nums,target,0,dp);
    }
};
