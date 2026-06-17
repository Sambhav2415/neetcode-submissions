class Solution {
public:
    int ans = 0;
    void rec(vector<int>& nums,int i,int recent){
        if(i == nums.size()){
            ans += recent;
            return;
        }
        rec(nums,i+1,recent^nums[i]);
        rec(nums,i+1,recent);
    }
    int subsetXORSum(vector<int>& nums) {
        rec(nums,0,0);
        return ans;
    }
};