class Solution {
public:
    void dfs(int src,int node,vector<vector<int>>&graph,vector<vector<bool>>&reach){
        for(int neigh : graph[node]){
            if(!reach[src][neigh]){
                reach[src][neigh] = true;
                dfs(src,neigh,graph,reach);
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> vec(n);
        for(auto &t : prerequisites){
            vec[t[0]].push_back(t[1]);
        }
        vector<vector<bool>> reach(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dfs(i,i,vec,reach);
        }
        vector<bool> ans;
        for(auto pai : queries){
            ans.push_back(reach[pai[0]][pai[1]]);
        }
        return ans;
    }
};