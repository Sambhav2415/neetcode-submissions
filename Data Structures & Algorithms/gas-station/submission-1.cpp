class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totSum = 0;
        int currSum =0;
        int startIdx = 0;
        for(int i=0;i<gas.size();i++){
            totSum += gas[i] - cost[i];
            currSum += gas[i] - cost[i];
            if(currSum < 0){
                currSum =0;
                startIdx = i+1;
            }
        }
        if(totSum < 0){
            return -1;
        }
        return startIdx;
    }
};
