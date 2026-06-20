class Solution {
public:
    int numSquares(int n) {
        vector<int> square;
        for(int i=1;i*i<=n;i++){
            square.push_back(i*i);
        }
        int k = square.size();
        int t = INT_MAX -100;
        vector<vector<int>> dp(n+1,vector<int>(k+1,t));
        for(int i=0;i<=k;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j] = dp[i][j-1];
                if(i >= square[j-1]){
                    dp[i][j] = min(dp[i][j] , 1+dp[i-square[j-1]][j]);
                }
            }
        }
        return dp[n][k];
    }
};