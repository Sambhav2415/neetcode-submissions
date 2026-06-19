class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        priority_queue<vector<int>,vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({0,0,0});
        int rows[4] = {0,0,-1,1};
        int cols[4] = {1,-1,0,0};
        while(!pq.empty()){
            auto vec = pq.top();
            pq.pop();
            int effort = vec[0];
            int i = vec[1];
            int j = vec[2];
            if(i==n-1 && j == m-1){
                return effort;
            }
            if(effort > dist[i][j]){
                continue;
            }  
            for(int k=0;k<4;k++){
                int nr = i+rows[k];
                int nc = j+cols[k];
                if(nr>=0 && nr<n && nc>=0 && nc <m){
                    int diff = abs(heights[i][j]-heights[nr][nc]);
                    int newEffort = max(effort, diff);
                    if(dist[nr][nc] > newEffort){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort,nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};