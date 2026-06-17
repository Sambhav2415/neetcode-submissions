class Solution {
public:
    int rec(vector<int>& nums, int target , vector<int>&dp){
        if(target == 0){
            return 1;
        }
        if(dp[target] != -1){
            return dp[target];
        }
        int ways = 0;
        for(int num : nums){
            if(num <= target){
                ways += rec(nums,target-num,dp);
            }
        }
        return dp[target]=ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return rec(nums,target,dp);
    }
};