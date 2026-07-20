class Solution {
public:
    bool dfs(vector<vector<int>>& edges,vector<bool>&vis,int src,int par){
        vis[src] = true;
        for(auto &v:edges){
            if(v[0] == src){
                if(!vis[v[1]]){
                    if(dfs(edges,vis,v[1],v[0])){
                        return true;
                    }
                }else{
                    if(v[1]==par){
                        continue;
                    }else{
                        return true;
                    }
                }
            }else if(v[1] == src){
                if(!vis[v[0]]){
                    if(dfs(edges,vis,v[0],v[1])){
                        return true;
                    }
                }else{
                    if(v[0]==par){
                        continue;
                    }else{
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }
        vector<bool> visited(n,false);

        if(dfs(edges,visited,0,-1)){
            return false;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};
