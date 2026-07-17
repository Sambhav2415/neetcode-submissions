class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void rec(vector<int>& nums,int idx,vector<int>&curr){
        ans.push_back(curr);
        for(int i=idx;i<n;i++){
            if(i != idx && nums[i]==nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            rec(nums,i+1,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        vector<int> curr;
        rec(nums,0,curr);
        return ans;
    }
};
