class Solution {
public:
    bool toCheck(vector<int>& nums,int k,int target,vector<int>&sides,int idx){
        if(idx == nums.size()){
            return true;
        }
        for(int i=0;i<k;i++){
            if(sides[i]+nums[idx] > target){
                continue;
            }
            sides[i] += nums[idx];
            if(toCheck(nums,k,target,sides,idx+1)){
                return true;
            }
            sides[i] -= nums[idx];
            if(sides[i] == 0)
                break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum =0;
        for(int num:nums){
            sum += num;
        }
        if(sum % k != 0){
            return false;
        }
        sort(nums.begin(),nums.end());
        int target = sum/k;
        int n = nums.size();
        if(nums[n-1] > target){
            return false;
        }
        vector<int> sides(k,0);
        return toCheck(nums,k,target,sides,0);
    }
};