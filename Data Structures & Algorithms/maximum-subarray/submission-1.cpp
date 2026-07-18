class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int count = 0;
        for(int num:nums){
            count += num;
            ans = max(ans,count);
            count = max(0,count);
        }
        return ans;
    }
};
