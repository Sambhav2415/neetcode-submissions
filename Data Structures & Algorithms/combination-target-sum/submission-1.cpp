class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void solve(vector<int>& nums, int target,vector<int> &count , int i){
        if(target == 0){
            ans.push_back(count);
            return;
        }
        if(i == n || nums[i] > target){
            return;
        }

        solve(nums,target,count,i+1);

        count.push_back(nums[i]);
        solve(nums,target-nums[i],count,i);
        count.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> count;
        solve(nums,target,count,0);
        return ans;
    }
};
