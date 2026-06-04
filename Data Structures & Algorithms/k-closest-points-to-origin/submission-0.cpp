class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            long long dist = (x*x+y*y);
            pq.push({dist,i});
        }
        vector<vector<int>> ans;
        int x=0;
        while(!pq.empty() && x<k){
            auto [d,i] = pq.top();
            pq.pop();
            ans.push_back(points[i]);
            x++;
        }
        return ans;
    }
};
