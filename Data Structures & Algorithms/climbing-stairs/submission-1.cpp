class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }else if(n==2){
            return 2;
        }
        int prev = 2;
        int secPrev = 1;
        int count;
        for(int i=3;i<=n;i++){
            count = prev+secPrev;
            secPrev = prev;
            prev = count;
        }
        return count;
    }
};
