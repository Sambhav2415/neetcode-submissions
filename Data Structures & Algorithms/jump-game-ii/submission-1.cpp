class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpJump(n,-1);
        dpJump[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j<n){
                    if(dpJump[i+j] == -1){
                        dpJump[i+j] = dpJump[i]+1;
                    }else{
                        dpJump[i+j] = min(dpJump[i]+1,dpJump[i+j]);
                    }
                }
            }
        }
        return dpJump[n-1];
    }
};
