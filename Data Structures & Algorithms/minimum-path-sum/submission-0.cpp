class Solution {
public:
    vector<vector<int>> dp;
    int m,n;
    
    int solve(int r ,int c ,vector<vector<int>>& obstacleGrid){
        if(r == m - 1 && c == n - 1)
            return obstacleGrid[r][c];
            
        if(r >= m || c >=n){
            return 1e9;
        }
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        return dp[r][c] = obstacleGrid[r][c]+min(solve(r+1,c,obstacleGrid),solve(r,c+1,obstacleGrid));
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<int>(n,-1));
        return solve(0,0,grid);
    }
};