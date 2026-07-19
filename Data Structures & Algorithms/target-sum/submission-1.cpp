class Solution {
public:
    int tar,n;
    int solve(vector<int>& nums, int sum,vector<vector<int>>&dp,int idx){
        if(idx == n){
            if(sum == tar){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[idx][sum+1000] != -1){
            return dp[idx][sum+1000];
        }
        int ways = 0;
        ways = solve(nums,sum+nums[idx],dp,idx+1)+solve(nums,sum-nums[idx],dp,idx+1);
        return dp[idx][sum+1000] = ways;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        tar = target;
        n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2001,-1));
        return solve(nums,0,dp,0);
    }
};
