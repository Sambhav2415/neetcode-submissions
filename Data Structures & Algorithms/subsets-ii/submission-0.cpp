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

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        subset(nums,0,temp);
        for(auto &v : ans){
            sort(v.begin(), v.end());
        }
        set<vector<int>> s(ans.begin(), ans.end());
        vector<vector<int>> an(s.begin(), s.end());
        return an;
    }
};
