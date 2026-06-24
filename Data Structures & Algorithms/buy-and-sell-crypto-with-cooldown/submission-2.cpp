class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int toCheck(vector<int>& prices,int idx,bool canBuy){
        if(idx >= n){
            return 0;
        }
        if(dp[idx][canBuy] != -1){
            return dp[idx][canBuy];
        }
        if(canBuy){
            return dp[idx][canBuy] =max(-prices[idx]+toCheck(prices,idx+1,0),toCheck(prices,idx+1,1));
        }else{
            return dp[idx][canBuy]= max(prices[idx]+toCheck(prices,idx+2,1) , toCheck(prices,idx+1,0));
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return toCheck(prices,0,1);
    }
};
