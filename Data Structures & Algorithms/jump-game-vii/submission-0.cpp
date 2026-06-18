class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int k = s.size();
        if(s[k-1] == '1'){
            return false;
        }
        vector<bool> dp(k,false);
        dp[0] = true;
        for(int i = 0;i<k;i++){
            if(!dp[i]){
                continue;
            }
            for(int j = minJump ; j <= maxJump ; j++){
                int pos = i+j;
                if(pos >= k){
                    break;
                }
                if(s[pos] == '0'){
                    dp[pos] = true;
                }
            }
        }
        return dp[k-1];
    }
};