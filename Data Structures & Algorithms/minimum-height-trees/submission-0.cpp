class Solution {
public:
    vector<int> mht;

    int bfs(vector<vector<int>>&graph,int src,int n){
        vector<bool> vis(n,false);
        queue<pair<int,int>> q;
        vis[src] = true;
        q.push({src,0});
        int ans = 0;
        while(!q.empty()){
            auto [u,step] = q.front();
            q.pop();
            ans = max(ans,step);
            for(int neigh:graph[u]){
                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push({neigh,step+1});
                }
            }
        }
        return ans;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto vec:edges){
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        mht.assign(n,-1);
        vector<int> ans;
        for(int i=0;i<n;i++){
            mht[i] = bfs(graph,i,n);
        }
        int minHeight = INT_MAX;
        for(int num : mht){
            minHeight = min(minHeight,num);
        }
        for(int i=0;i<n;i++){
            if(mht[i] == minHeight){
                ans.push_back(i);
            }
        }
        return ans;
    }
};