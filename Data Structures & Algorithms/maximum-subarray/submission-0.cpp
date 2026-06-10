class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int currSum = 0;
        int n = nums.size();
        int st =0;
        int end = n-1;
        while(st<=end){
            currSum += nums[st];
            ans = max(currSum , ans);
            if(currSum <0){
                currSum = 0;
            }
            st++;
        }
        return ans;
    }
};
