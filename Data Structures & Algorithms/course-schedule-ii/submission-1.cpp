class Solution {
public:
    bool isCycle(int src,vector<bool>&rec,vector<bool>&vis,vector<vector<int>>&graph){
        vis[src]=true;
        rec[src]=true;
        for(int num:graph[src]){
            if(!vis[num]){
                if(isCycle(num,rec,vis,graph)){
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

    void topoOrder(int src,vector<bool>&vis,stack<int>&s,vector<vector<int>>&graph){
        vis[src] = true;
        for(int num:graph[src]){
            if(!vis[num]){
                topoOrder(num,vis,s,graph);
            }
        }
        s.push(src);    
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(n);
        for(auto &t:prerequisites){
            graph[t[1]].push_back(t[0]);
        }
        vector<bool> vis(n,false);
        vector<bool> rec(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(i,rec,vis,graph)){
                    return {};
                }
            }
        }
        stack<int> s;
        vector<bool> vis2(n,false);
        for(int i=0;i<n;i++){
            if(!vis2[i]){
                topoOrder(i,vis2,s,graph);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
