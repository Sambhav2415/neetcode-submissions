class Solution {
public:
    int n,m;
    void dfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int i,int j){
        vis[i][j] = true;
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        for(int k=0;k<4;k++){
            int nr = i+row[k];
            int nc = j+col[k];
            if(nr >=0 && nr < n && nc>=0 && nc<m && grid[nr][nc] == '1' && !vis[nr][nc]){
                dfs(grid,vis,nr,nc);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        }    
        return ans;
    }
};
