class Solution {
public:
    int sum , n;
    void rec(vector<int>& nums,int idx,int xorSum){
        if(idx == n){
            sum += xorSum;
            return ;
        }
        rec(nums,idx+1,xorSum^nums[idx]);
        rec(nums,idx+1,xorSum);
        
    }

    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        sum = 0;
        rec(nums,0,0);
        return sum;
    }
};