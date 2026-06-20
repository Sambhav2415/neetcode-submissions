class Solution {
public:
    vector<vector<int>> dp;
    int m,n;
    
    int solve(int r ,int c ,vector<vector<int>>& obstacleGrid){
        if(r >= m || c >=n || obstacleGrid[r][c] == 1){
            return 0;
        }
        if(r == m - 1 && c == n - 1)
            return 1;

        if(dp[r][c] != -1){
            return dp[r][c];
        }
        return dp[r][c] = solve(r+1,c,obstacleGrid)+solve(r,c+1,obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        dp.assign(m,vector<int>(n,-1));
        return solve(0,0,obstacleGrid);
    }
};