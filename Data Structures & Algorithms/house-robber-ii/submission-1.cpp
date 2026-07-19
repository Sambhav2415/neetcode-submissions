class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }else if(n ==2){
            return max(nums[0],nums[1]);
        }else if(n==3){
            return max(nums[2],max(nums[0],nums[1]));
        }
        vector<int> dp0(n,0);
        dp0[0] = nums[0];
        dp0[1] = max(nums[0],nums[1]);
        int j;
        vector<int> dp1(n,0);
        dp1[1] = nums[1];
        dp1[2] = max(nums[2],nums[1]);
        for(int i=2;i<n-1;i++){
            dp0[i] = max(dp0[i-1],dp0[i-2]+nums[i]);
            j = i+1;
            dp1[j] = max(dp1[j-1],dp1[j-2]+nums[j]);
        }
        return max(dp0[n-2],dp1[n-1]);
    }
};
