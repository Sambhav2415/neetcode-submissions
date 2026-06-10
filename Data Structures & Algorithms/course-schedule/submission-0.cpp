class Solution {
public:
    bool isCycle(int src,vector<bool> &vis,vector<bool> &rec,vector<vector<int>>& graph){
        vis[src] = true;
        rec[src] = true;
        for(int num : graph[src]){
            if(!vis[num]){
                if(isCycle(num,vis,rec,graph)){
                    return true;
                }
            }else{
                if(rec[num]){
                    return true;
                }
            }
        }
        rec[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> vec(n);
        for(auto &t : prerequisites){
            vec[t[1]].push_back(t[0]);
        }
        vector<bool> vis(n,false);
        vector<bool> rec(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(i,vis,rec,vec)){
                    return false;       
                }
            }
        }
        return true;
    }
};
