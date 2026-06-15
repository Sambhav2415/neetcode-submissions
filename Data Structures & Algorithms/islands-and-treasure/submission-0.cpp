class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            int row[4] = {-1,1,0,0};
            int col[4] = {0,0,1,-1};
            for(int k=0;k<4;k++){
                int nr = row[k] + i;
                int nc = col[k] + j;
                if(nr < n && nr>=0 && nc < m && nc >=0){
                    if(grid[nr][nc] == -1){
                        continue;
                    }else if(grid[nr][nc] == 2147483647){
                        grid[nr][nc] = grid[i][j] + 1;
                        q.push({nr,nc});
                    }else if(grid[nr][nc] != 0){
                        int dist = min(grid[nr][nc] , grid[i][j]+1);
                        if(dist < grid[nr][nc]){
                            grid[nr][nc] = dist;
                            q.push({nr,nc});
                        }
                    }
                }else{
                    continue;
                }
            }
        }
    }
};
