class Solution {
public:
    int n,m;
    int dr[4] = {0,0,-1,1};
    int dc[4] = {1,-1,0,0};
    int longSeq(vector<vector<int>>& matrix,vector<vector<int>>& dp,int r,int c){
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int ans = 1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr>=0&&nr<n&&nc>=0&&nc<m && matrix[r][c] < matrix[nr][nc]){
                ans = max(ans , 1+longSeq(matrix,dp,nr,nc));
            }
        }
        return dp[r][c] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans , longSeq(matrix,dp,i,j));
            }
        }
        return ans;
    }
};
