class Solution {
public:
    vector<vector<int>> graph;
    int n;

    bool hasCycleHelper(vector<bool>&vis,int src,int par){
        vis[src] = true;
        for(int neigh:graph[src]){
            if(!vis[neigh]){
                if(hasCycleHelper(vis,neigh,src)){
                    return true;
                }
            }else{
                if(neigh != par){
                    return true;
                }
            }
        }
        return false;
    }

    bool hasCycle(int src){
        vector<bool> vis(n,false);
        if(hasCycleHelper(vis,src,-1)){
            return true;
        }else{
            return false;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        graph.assign(n+1,vector<int>());
        int src = edges[0][0];

        for(int i=0;i<=n-1;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            if(hasCycle(src)){
                return edges[i];
            }
            
        }

        return edges[n-1];

    }
};
