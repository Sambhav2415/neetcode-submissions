class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        for(int i=1;i*i<=n;i++){
            sq.push_back(i*i);
        }
        int t = 1e7-100;
        int p = sq.size();
        vector<vector<int>> dp(n+1,vector<int>(p+1,t));
        for(int i=0;i<=p;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=p;j++){
                if(sq[j-1] <= i){
                    dp[i][j] = min(dp[i][j-1],1+dp[i-sq[j-1]][j]);
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[n][p];
    }
};