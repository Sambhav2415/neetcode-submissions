class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});

        int row[4] = {0, 0, 1, -1};
        int col[4] = {1, -1, 0, 0};

        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();

            int i = v[1];
            int j = v[2];

            if(i == n-1 && j == n-1){
                return v[0];
            }
            if(vis[i][j]){
                continue;
            }

            vis[i][j] = true;
            for(int k=0;k<4;k++){
                int nr = row[k]+i;
                int nc = col[k]+j;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]){
                    int newTime = max(v[0] , grid[nr][nc]);
                    pq.push({newTime,nr,nc});
                }
            }
        }
        return -1;
    }
};
