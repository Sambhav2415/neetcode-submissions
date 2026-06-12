class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        int n = coins.size();
        int INF = 100000;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,INF));
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int coin = coins[i-1];
                if(coin <= j){
                    dp[i][j] = min(1+dp[i][j-coin] , dp[i-1][j]);
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][amount]== INF){
            return -1;
        }else{
            return dp[n][amount];
        }
    }
};
