class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void subset(vector<int>& nums , int idx , vector<int> &temp){
        ans.push_back(temp);

        for(int i=idx;i<n;i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            subset(nums,i+1,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        sort(nums.begin(),nums.end());
        subset(nums,0,temp);
        return ans;
    }
};
