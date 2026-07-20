class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int node, int parent) {
        vis[node] = true;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                if (dfs(adj, vis, nei, node))
                    return true;
            }
            else if (nei != parent) {
                return true;      // cycle
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        if (dfs(adj, vis, 0, -1))
            return false;

        for (bool x : vis)
            if (!x)
                return false;

        return true;
    }
};
