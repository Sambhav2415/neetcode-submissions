class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> vec(n+1);
        for(auto &e:times){
            vec[e[0]].push_back({e[1],e[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        pq.push({0,k});
        while(pq.size()>0){
            auto [wt,u] = pq.top();
            pq.pop();

            if(wt > dist[u]){
                continue;
            }else{
                for(auto &e : vec[u]){
                    int w = e.second;
                    int v = e.first;
                    if(dist[v] > w + dist[u]){
                        dist[v] = w+dist[u];
                        pq.push({dist[v],v});
                    }
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            int num = dist[i];
            if(num == INT_MAX ){
                return -1;
            }
            ans = max(ans , num);
        }
        return ans;
    }
};
