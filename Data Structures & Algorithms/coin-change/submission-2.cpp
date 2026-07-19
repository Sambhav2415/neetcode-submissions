class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int t = 1e5;
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,t));
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                dp[i][j] = dp[i-1][j];
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i][j],1+dp[i][j-coins[i-1]]);
                }
            }
        }
        return dp[n][amount] == t?-1:dp[n][amount];

    }
};
