class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int src = 0;
        vector<bool> mst(v,false);
        pq.push({0,0});
        int minCost = 0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(!mst[idx]){
                minCost += cost;
                mst[idx] = true;
                for(int i=0;i<v;i++){
                    if(idx != i ){
                        int wt = abs(points[i][0]-points[idx][0]) + abs(points[i][1]-points[idx][1]);
                        pq.push({wt,i});
                    }
                }
            }
        }
        return minCost;
    }
};
