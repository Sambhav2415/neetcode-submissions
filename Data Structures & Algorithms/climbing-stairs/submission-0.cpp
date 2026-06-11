class Solution {
public:
    int climbStairs(int n) {
        vector<int> dist(n+1,1);
        for(int i=2;i<=n;i++){
            dist[i] = dist[i-1]+dist[i-2];
        }
        return dist[n];
    }
};
