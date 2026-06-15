class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j,int &ans){
        vis[i][j] = true;
        ans++;
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        for(int k=0;k<4;k++){
            int nr = i+row[k];
            int nc = j+col[k];
            if(nr >=0 && nr < n && nc>=0 && nc<m && grid[nr][nc] == 1 && !vis[nr][nc]){
                dfs(grid,vis,nr,nc,ans);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ans = 0;
                if(grid[i][j] == 1 && !vis[i][j]){
                    dfs(grid,vis,i,j,ans);
                    res = max(ans , res);
                }
            }
        }    
        return res;
    }
};
