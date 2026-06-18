class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = right;
        for(int i=left;i<right;i++){
            if(ans == 0){
                break;
            }
            ans = ans&i;
        }
        return ans;
    }
};