class Solution {
public:
    void dfs(vector<vector<int>> &graph , vector<bool>&vis,int src){
        vis[src] = true;
        for(int num:graph[src]){
            if(!vis[num]){
                dfs(graph,vis,num);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto &t : edges){
            graph[t[0]].push_back(t[1]);
            graph[t[1]].push_back(t[0]);
        }
        int ans = 0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(graph,vis,i);
            }
        }
        return ans;
    }
};
