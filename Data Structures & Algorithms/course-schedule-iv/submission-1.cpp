class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<bool>> reach;

    void dfs(int src , int node){
        for(int neigh:graph[node]){
            if(!reach[src][neigh]){
                reach[src][neigh] = true;
                dfs(src,neigh);
            }
        }
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        graph.resize(n);
        for(auto &t:prerequisites){
            graph[t[0]].push_back(t[1]);
        }
        reach.assign(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dfs(i,i);
        }
        vector<bool> ans;
        for(auto& t:queries){
            if(reach[t[0]][t[1]]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};