class Solution {
public:
    int n;

    int rec(vector<int>& prices,vector<vector<int>>&dp,int idx,int canBuy){
        if(idx >= n){
            return 0;
        }
        if(dp[idx][canBuy] != -1){
            return dp[idx][canBuy];
        }
        if(canBuy){
            return dp[idx][canBuy] = max(rec(prices,dp,idx+1,1),rec(prices,dp,idx+1,0)-prices[idx]);
        }else{
            return dp[idx][canBuy] = max(rec(prices,dp,idx+1,0),rec(prices,dp,idx+2,1)+prices[idx]);
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        if(n <= 1){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return rec(prices,dp,0,1);
    }
};
