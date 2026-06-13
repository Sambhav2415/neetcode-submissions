class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<vector<int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(),vec.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0]){
                return b[1]<b[1];
            }
            return b[0] < a[0];
        });
        double time = (double)(target-vec[0][0])/(vec[0][1]);
        int ans = 1;
        for(int i=1;i<n;i++){
            double currTime = (double)(target-vec[i][0])/(vec[i][1]);
            if(currTime <= time){
                continue;
            }else{
                ans++;
                time = currTime;
            }
        }
        return ans;
    }
};
