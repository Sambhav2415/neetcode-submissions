class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpJump(n,-1);
        dpJump[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                int idx = i+j;
                if(idx < n){
                    if(dpJump[idx]==-1){
                        dpJump[idx] = dpJump[i]+1;
                    }else{
                        dpJump[idx] = min(dpJump[i]+1,dpJump[idx]);
                    }
                }
            }
        }
        return dpJump[n-1];
    }
};
