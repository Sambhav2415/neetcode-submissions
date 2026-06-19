class Solution {
public:
    bool rec(vector<int>& matchsticks,vector<int>&sides,int target,int idx){

        if(idx == matchsticks.size()){
            return true;
        }

        for(int i=0;i<4;i++){
            if(sides[i] + matchsticks[idx] > target){
                continue;
            }
            sides[i] += matchsticks[idx];
            if(rec(matchsticks,sides,target,idx+1)){
                return true;
            }
            sides[i] -= matchsticks[idx];
            if(sides[i]==0){
                break;
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int num:matchsticks){
            sum += num;
        }
        if(sum %4 !=0 || matchsticks.size()<4){
            return false;
        }
        sort(matchsticks.rbegin(),matchsticks.rend());
        int target = sum/4;
        if(matchsticks[0]>target){
            return false;
        }
        vector<int> side = {0,0,0,0};

        return rec(matchsticks,side,target,0);
    }
};