class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int l = 0;
        int len = INT_MAX;
        for(int r=0;r<nums.size();r++){
            sum += nums[r];
            while(sum >= target){
                len = min(len,r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        return len == INT_MAX?0:len;
    }
};