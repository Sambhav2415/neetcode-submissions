class Solution {
public:
    bool rec(vector<int>& matchsticks,vector<int>&sides,int target,int idx,int k){

        if(idx == matchsticks.size()){
            return true;
        }
        for(int i=0;i<k;i++){
            if(sides[i]+matchsticks[idx] > target){
                continue;
            }
            sides[i] += matchsticks[idx];
            if(rec(matchsticks,sides,target,idx+1,k)){
                return true;
            }
            sides[i] -= matchsticks[idx];
            if(sides[i] == 0){
                break;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& matchsticks, int k) {
        int sum = 0;
        for(int num:matchsticks){
            sum += num;
        }
        if(sum %k !=0){
            return false;
        }
        sort(matchsticks.rbegin(),matchsticks.rend());
        int target = sum/k;
        if(matchsticks[0]>target){
            return false;
        }
        vector<int> side(k,0);

        return rec(matchsticks,side,target,0,k);
    }
};