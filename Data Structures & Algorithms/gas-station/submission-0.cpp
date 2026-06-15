class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totSum = 0;
        for(int i=0;i<gas.size();i++){
            totSum += gas[i] - cost[i];
        }
        if(totSum < 0){
            return -1;
        }
        int idx = 0;
        int tank = 0;
        for(int i=0;i<gas.size();i++){
            tank += gas[i] - cost[i];
            if(tank <0){
                idx = i+1;
                tank = 0;
            }
        }
        return idx;
    }
};
