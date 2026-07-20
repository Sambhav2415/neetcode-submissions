class Solution {
public:
    vector<vector<bool>> vis;
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};
    int n,m;

    void dfs(int r,int c,vector<vector<char>>& grid){
        vis[r][c] = true;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]=='1' && !vis[nr][nc]){
                dfs(nr,nc,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n,vector<bool>(m,false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans+=1;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};
