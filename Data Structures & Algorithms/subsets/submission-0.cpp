class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void subset(vector<int>& nums , int i , vector<int> temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        subset(nums,i+1,temp);

        temp.push_back(nums[i]);
        subset(nums,i+1,temp);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        subset(nums,0,temp);
        return ans;
    }
};
