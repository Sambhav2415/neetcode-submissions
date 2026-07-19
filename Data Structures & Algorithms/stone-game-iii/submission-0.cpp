class Solution {
public:
    vector<int> dp;
    int n;

    int solve(vector<int>& stoneValue,int idx){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != INT_MIN){
            return dp[idx];
        }
        int ans = INT_MIN;
        int sum = 0;
        for(int i=0;i<3&&i+idx<n;i++){
            sum += stoneValue[i+idx];
            ans = max(ans , sum-solve(stoneValue,i+idx+1));
        }
        return dp[idx] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n,INT_MIN);
        int diff = solve(stoneValue,0);
        if(diff <0){
            return "Bob";
        }else if(diff >0){
            return "Alice";
        }else{
            return "Tie";
        }
    }
};