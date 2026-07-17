class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void rec(vector<int>& nums,int idx,vector<int>currSubset){
        if(idx == n){
            ans.push_back(currSubset);
            return;
        }
        currSubset.push_back(nums[idx]);
        rec(nums,idx+1,currSubset);
        currSubset.pop_back();

        rec(nums,idx+1,currSubset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        rec(nums,0,{});
        return ans;
    }
};
