class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = nums[0];
        for(int i=0;i<n;i++){
            if(i>maxReach){
                return false;
            }
            if(nums[i]+i > maxReach){
                maxReach = nums[i]+i;
            }
        }
        return maxReach >= n-1;
    }
};
