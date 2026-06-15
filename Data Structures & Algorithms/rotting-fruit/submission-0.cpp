class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty()){
            auto [st,p] = q.front();
            int i = p.first;
            int j = p.second;
            q.pop();
            int row[4] = {0,0,-1,1};
            int col[4] = {1,-1,0,0};
            ans = max(st,ans);
            for(int k=0;k<4;k++){
                int nr = i+row[k];
                int nc = j+col[k];
                if(nr>=0 && nr<n && nc>=0 && nc < m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    q.push({st+1,{nr,nc}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
