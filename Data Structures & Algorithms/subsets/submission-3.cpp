class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void dp(vector<int>& nums,int idx,vector<int>&curr){
        if(idx == n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        dp(nums,idx+1,curr);
        curr.pop_back();
        dp(nums,idx+1,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        dp(nums,0,curr);
        return ans;
    }
};
