class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        int n = intervals.size();
        int i=0;
        while(i < n){
            int s = ans.size();
            if(s ==0){
                ans.push_back(intervals[i]);
            }else{
                if(ans[s-1][1] >= intervals[i][0]){
                    ans[s-1][1] = max(ans[s-1][1],intervals[i][1]);
                }else{
                    ans.push_back(intervals[i]);
                }
            }
            i++;
        }
        return ans;
    }
};
