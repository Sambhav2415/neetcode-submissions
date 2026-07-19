class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        vector<int> vec(st.begin(),st.end());
        sort(vec.begin(),vec.end());
        int n = nums.size();
        int m = vec.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums[i-1]==vec[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
