class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int minEnd = intervals[0][1];
        int ans = 0;
        for(int i=1;i<n;i++){
            if(minEnd <= intervals[i][0]){
                minEnd = intervals[i][1];
            }else{
                minEnd = min(intervals[i][1],minEnd);
                ans++;
            }
        }
        return ans;
    }
};
