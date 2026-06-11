class Solution {
public:
    int findCheapestPrice(int n,vector<vector<int>>&flights,int src,int dst,int k){
        vector<vector<pair<int,int>>> vec(n);
        for(auto &e:flights){
            vec[e[0]].push_back({e[1],e[2]});
        }
        queue<pair<int, pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        pq.push({0,{-1,src}});
        while(!pq.empty()){
            auto [d,x] = pq.front();
            pq.pop();
            int st = x.first;
            int u = x.second;
            for(auto &e : vec[u]){
                int wt = e.second;
                int v = e.first;
                if(dist[v] > d+wt && st+1<=k){
                    dist[v] = d+wt;
                    pq.push({dist[v],{st+1,v}});
                }
            }
        }
        return dist[dst] == INT_MAX?-1:dist[dst];
    }
};
