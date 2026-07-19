class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int solve(vector<int>& stoneValue,int stIdx,int endIdx){
        if(stIdx > endIdx)
            return 0;
            
        if(dp[stIdx][endIdx] != INT_MIN){
            return dp[stIdx][endIdx];
        }
        int ans = INT_MIN;
        ans = max(ans , stoneValue[stIdx]-solve(stoneValue,stIdx+1,endIdx));
        ans = max(ans , stoneValue[endIdx]-solve(stoneValue,stIdx,endIdx-1));
        return dp[stIdx][endIdx] = ans;
    }

    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        dp.assign(n,vector<int>(n,INT_MIN));
        int diff = solve(piles,0,n-1);
        if(diff <0){
            return false;
        }else {
            return true;
        }
    }
};