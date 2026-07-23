class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int low = 0;
        int high = mp[key].size()-1;
        string res = "";
        while(low <= high){
            int mid = low+(high-low)/2;
            int tS = mp[key][mid].first;
            if(tS == timestamp){
                return mp[key][mid].second;
            }else if(tS > timestamp){
                high = mid-1;
            }else{
                low = mid+1;
                res = mp[key][mid].second;
            }
        }
        return res;
    }
};
