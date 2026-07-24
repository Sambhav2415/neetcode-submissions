class Solution {
public:
    int ans =0;
    int n;

    void dp(vector<int>& nums,int idx,int sum){
        if(idx == n){
            ans += sum;
            return;
        }
        dp(nums,idx+1,sum^nums[idx]);
        dp(nums,idx+1,sum);
    }

    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        dp(nums,0,0);
        return ans;
    }
};