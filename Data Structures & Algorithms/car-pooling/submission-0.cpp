class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> events;

        for(auto &trip : trips){
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            events.push_back({from, passengers});
            events.push_back({to, -passengers});
        }

        sort(events.begin(), events.end());
        int count = 0;
        for(auto &[loc,pass]:events){
            count += pass;

            if(count > capacity){
                return false;
            }
        }
        return true;
    }
};