class Solution {
public:
    vector<vector<int>> ans;

    void allSubset(vector<int>& nums,vector<int> count,int i){
        if(i==nums.size()){
            ans.push_back(count);
            return;
        }
        count.push_back(nums[i]);
        allSubset(nums,count,i+1);
        count.pop_back();
        
        allSubset(nums,count,i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        allSubset(nums,{},0);
        return ans;
    }
};
