class Solution {
public:
    int target;
    bool dfs(vector<int>& nums, int k,int idx,vector<int>&sides){
        if(idx == nums.size()){
            return true;
        }
        for(int i=0;i<k;i++){
            if(nums[idx]+sides[i] <=target){
                sides[i] += nums[idx];
                if(dfs(nums,k,idx+1,sides)){
                    return true;
                }
                sides[i] -= nums[idx];
            }
            if(sides[i] == 0)
                break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int num:nums){
            sum += num;
        }
        if(sum %k !=0 || nums.size()<k){
            return false;
        }
        sort(nums.rbegin(),nums.rend());
        target = sum/k;
        if(nums[0]>target){
            return false;
        }
        vector<int> sides(k,0);
        return dfs(nums,k,0,sides);
    }
};