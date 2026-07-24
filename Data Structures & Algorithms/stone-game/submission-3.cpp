class Solution {
public:
    int rec(vector<int>& piles,int stIdx,int endIdx,vector<vector<int>>& dp){
        if(stIdx>endIdx){
            return 0;
        }
        if(dp[stIdx][endIdx] != INT_MIN){
            return dp[stIdx][endIdx];
        }
        
        return dp[stIdx][endIdx] = max(piles[stIdx]-rec(piles,stIdx+1,endIdx,dp),
                                    piles[endIdx]-rec(piles,stIdx,endIdx-1,dp));
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MIN));
        int diff = rec(piles,0,n-1,dp);
        if(diff < 0){
            return false;
        }else {
            return true;
        }
    }
};